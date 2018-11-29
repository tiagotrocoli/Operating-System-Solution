package com.project;

import java.util.Collection;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class FCFS extends Scheduler{

    FCFS(Collection<Process> listOfProcess){
        super(listOfProcess);
        readyQueue = new LinkedList<>();
        readyQueue.addAll(listOfProcess);
    }


    @Override
    public void schedule(){

        while(!readyQueue.isEmpty()){

            Process p = readyQueue.remove();
            cpu.run(p,p.getBurstTime());
            metrics.updateMetric(p.getBurstTime());
            metrics.updateMetric(p);
        }

    }

}

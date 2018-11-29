package com.project;

import java.util.*;

public class Priority extends Scheduler {

    Priority(Collection<Process> listOfProcess){

        super(listOfProcess);
        readyQueue = new PriorityQueue<Process>(100, comp);
        readyQueue.addAll(listOfProcess);

    }

    private static Comparator<Process> comp = new Comparator<Process>(){
        @Override
        public int compare(Process o1, Process o2){
            return o1.getPriority() - o2.getPriority();
        }
    };

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

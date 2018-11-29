package com.project;

import java.util.*;

public class RoundRobin extends Scheduler{

    protected int cpuBurst = 10;

    RoundRobin(Collection<Process> listOfProcess, int cpuBurst){

        super(listOfProcess);

        readyQueue  = new LinkedList<>();
        readyQueue.addAll(listOfProcess);

        this.cpuBurst = cpuBurst;

    }

    RoundRobin(Collection<Process> listOfProcess){

        super(listOfProcess);

        readyQueue  = new LinkedList<>();
        readyQueue.addAll(listOfProcess);

    }


    @Override
    public void schedule(){

        while(readyQueue.size() > 1){

            // execute each one within the cpu burst time
            Process p = readyQueue.remove();

            int processTime = p.getBurstTime() > cpuBurst ? cpuBurst : p.getBurstTime();

            cpu.run(p,processTime);

            p.decreaseBurstTime(cpuBurst);

            metrics.updateMetric(processTime);

            if(p.getBurstTime()!=0) {
                readyQueue.add(p);

            }else{
                metrics.updateMetric(p);
            }
        }

        Process p = readyQueue.remove();
        cpu.run(p,p.getBurstTime());
        metrics.updateMetric(p.getBurstTime());
        metrics.updateMetric(p);
    }

}

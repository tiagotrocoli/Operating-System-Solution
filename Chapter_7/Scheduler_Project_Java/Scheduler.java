package com.project;

import java.util.Collection;
import java.util.Queue;

public abstract class Scheduler{

    protected Metrics metrics;
    protected Queue<Process> readyQueue;
    protected CPU cpu;

    protected Scheduler(Collection<Process> listOfProcess){
        metrics = new Metrics(listOfProcess);
        cpu     = new CPU();
    }

    abstract public void schedule();

    @Override
    public String toString(){
        return readyQueue.toString();
    }

    public void showMetrics(){
        System.out.println(metrics.toString());
    }

}

package com.project;
import java.util.Collection;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class SJF extends Scheduler {

    SJF(Collection<Process> listOfProcess){

        super(listOfProcess);
        readyQueue = new PriorityQueue<Process>(100,comp);
        readyQueue.addAll(listOfProcess);

    }

    protected static Comparator<Process> comp = new Comparator<Process>(){
        @Override
        public int compare(Process o1, Process o2){
            return o1.getBurstTime() - o2.getBurstTime();
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

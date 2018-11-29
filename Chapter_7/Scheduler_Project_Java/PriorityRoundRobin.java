package com.project;
import java.util.Collection;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class PriorityRoundRobin extends RoundRobin{

    private Queue<Process> priorityQueue;

    PriorityRoundRobin(Collection<Process> listOfProcess, int cpuBurst){

        super(listOfProcess, cpuBurst);
        priorityQueue  = new PriorityQueue<Process>(100 ,comp);
        priorityQueue.addAll(listOfProcess);

    }

    PriorityRoundRobin(Collection<Process> listOfProcess){

        super(listOfProcess);
        priorityQueue  = new PriorityQueue<Process>(100 ,comp);
        priorityQueue.addAll(listOfProcess);

    }

    protected static Comparator<Process> comp = new Comparator<Process>(){
        @Override
        public int compare(Process o1, Process o2){
            return o1.getPriority() - o2.getPriority();
        }
    };

    // Execute a process
    public void executeSchedule(){

        // While the execution is not finished, do:
        while(!priorityQueue.isEmpty()){

            // Remove the highest priority processes and add them to the linkedList from Round Robin instance
            int priority = priorityQueue.peek().getPriority();
            readyQueue.add(priorityQueue.remove());

            while(!priorityQueue.isEmpty() && priorityQueue.peek().getPriority() == priority){
                readyQueue.add(priorityQueue.remove());
            }

            // execute the Round Robin scheduler
            super.schedule();
        }

    }

    public void showProcess(){
        System.out.println("\n\n"+priorityQueue.toString());
    }

}
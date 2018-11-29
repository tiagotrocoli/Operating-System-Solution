package com.project;
import java.util.ArrayList;
import java.util.Random;

public class Main {

    public static void main(String args[]){

        // Instantiate random
        Random rand = new Random();

        // ArrayList of process
        ArrayList<Process> arr = new ArrayList<>();

        // Populate priority queue
        for(int i=0;i<4;i++) {
            arr.add(new Process("T" + Integer.toString(i), rand.nextInt(10),rand.nextInt(50 )));
        }

        // Instantiate a PriorityRoundRobin scheduler
        Scheduler sjf = new PriorityRoundRobin(arr,3);

        sjf.schedule();

        sjf.showMetrics();
    }
}

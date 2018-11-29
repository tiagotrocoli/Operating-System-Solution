package com.project;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Iterator;

public class RoundRobinTest {

    ArrayList<Process> arr;
    ArrayList<Integer> arrInt;

    @BeforeClass
    public static void init(){
        System.out.println("Turn Round Time Metrics");
    }

    @Before
    public void setUp(){

        arrInt  = new ArrayList<>();
        arr     = new ArrayList<>();

        arr.add(new Process("P1", 3, 10));
        arr.add(new Process("P2", 1, 1));
        arr.add(new Process("P3", 3, 2));
        arr.add(new Process("P4", 4, 1));
        arr.add(new Process("P5", 2, 5));

    }

    @Test
    public void testPriorityTurnRoundTime(){

        System.out.println("\nTesting Priority Scheduler");

        arrInt.add(16);
        arrInt.add(1);
        arrInt.add(18);
        arrInt.add(19);
        arrInt.add(6);

        Scheduler priority = new Priority(arr);

        priority.schedule();

        Iterator<Process> itp = arr.iterator();
        Iterator<Integer> iti = arrInt.iterator();

        while(itp.hasNext() && iti.hasNext()){
            assertEquals((int) iti.next(),priority.metrics.GetTurnRoundTime(itp.next()));
        }

    }

    @Test
    public void testSJFTurnRoundTime(){

        System.out.println("\nTesting SJF Scheduler");

        arrInt.add(19);
        arrInt.add(1);
        arrInt.add(4);
        arrInt.add(2);
        arrInt.add(9);

        Scheduler sjf = new SJF(arr);

        sjf.schedule();

        Iterator<Process> itp = arr.iterator();
        Iterator<Integer> iti = arrInt.iterator();

        while(itp.hasNext() && iti.hasNext()){
            assertEquals((int) iti.next(),sjf.metrics.GetTurnRoundTime(itp.next()));
        }
    }

    @Test
    public void testFCFSTurnRoundTime(){

        System.out.println("\nTesting FCFS Scheduler");

        arrInt.add(10);
        arrInt.add(11);
        arrInt.add(13);
        arrInt.add(14);
        arrInt.add(19);

        Scheduler fcfs = new FCFS(arr);

        fcfs.schedule();

        Iterator<Process> itp = arr.iterator();
        Iterator<Integer> iti = arrInt.iterator();

        while(itp.hasNext() && iti.hasNext()){
            assertEquals((int) iti.next(),fcfs.metrics.GetTurnRoundTime(itp.next()));
        }
    }

    @Test
    public void testRoundRobinTurnRoundTime(){

        System.out.println("\nTesting Round Robin Scheduler");

        arrInt.add(19);
        arrInt.add(2);
        arrInt.add(7);
        arrInt.add(4);
        arrInt.add(14);

        Scheduler rr = new RoundRobin(arr,1);

        rr.schedule();

        Iterator<Process> itp = arr.iterator();
        Iterator<Integer> iti = arrInt.iterator();

        while(itp.hasNext() && iti.hasNext()){
            assertEquals((int) iti.next(),rr.metrics.GetTurnRoundTime(itp.next()));
        }
    }
}

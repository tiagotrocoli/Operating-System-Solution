package com.project;

public class Process{

    private final String name;
    private final int priority;
    private int burstTime;

    Process(String name, int priority, int burstTime){

        this.name       = name;
        this.priority   = priority;
        this.burstTime  = burstTime;

    }

    void decreaseBurstTime(int num){

        burstTime -= num;

        if(burstTime < 0)
            burstTime = 0;
    }

    int getBurstTime(){
        return burstTime;
    }

    void decreseBurstTime(int num){
        burstTime = burstTime - num;
    }

    int getPriority(){
        return priority;
    }

    String getName(){
        return name;
    }

    public String toString(){
        return "(" + name + ", " + Integer.toString(priority) + ", " + Integer.toString(burstTime)+")";
    }
}

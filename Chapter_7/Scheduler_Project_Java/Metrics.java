package com.project;

import java.util.*;

public class Metrics {

    private HashMap<Process,Integer> turnRoundTime;
    private Collection<Process> arr;
    private int totalTime;
    private double turnRoundMean, watingTimeMean;

    Metrics(Collection<Process> listOfProcess){

        arr = listOfProcess;

        turnRoundTime = new HashMap<>();

        for(Process elem : listOfProcess){
            turnRoundTime.put(elem, 0);
        }

    }

    public void updateMetric(int timeSpend){
        totalTime += timeSpend;
    }

    public void updateMetric(Process p){
        turnRoundTime.put(p,totalTime);
    }

    @Override
    public String toString(){

        double mean = 0;
        String str  = "Turn Round Time\n";

        for(Process elem : arr){
            mean = mean + turnRoundTime.get(elem);
            str = str + elem.getName() + " Time:" + turnRoundTime.get(elem).toString() + "\n";
        }

        mean = (mean / (1.0*arr.size()) );

        return str + Double.toString(mean);
    }

    public int GetTurnRoundTime(Process p){
        return turnRoundTime.get(p);
    }

}

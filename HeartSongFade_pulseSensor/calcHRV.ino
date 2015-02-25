
void CalcHRV() {
  // keep a running total of the last 10 IBI values
  pulsetime = millis(); 

  IBI = pulsetime - lastpulsetime;        // measure time between beats in mS
  lastpulsetime = pulsetime;               // keep track of time for next pulse

     word runningTotal = 0;
    word runningTotalHRV = 0;                  // clear the runningTotal variable 
    word runningTotalDev = 0;   

  for(int i=0; i<=98; i++){                // shift data in the rate array
    rate[i] = rate[i+1];                  // and drop the oldest IBI value 
    runningTotal += rate[i];              // add up the 9 oldest IBI values
  }

  rate[99] = IBI;                          // add the latest IBI to the rate array

// OK math getting funky... var = sqrt (((rate[] - runningTotalHRV)*(rate[] - runningTotalHRV))/100)/100)

  if (rate[0] != 0){
    runningTotalHRV += rate[99];                // add the latest IBI to runningTotal
    runningTotalHRV /= 100;                     // calculate mean: average the last 100 IBI values 
    
    for(int i=0; i<=98; i++){                // shift data in the rate array
    rate[i] = rate[i+1];                  // and drop the oldest IBI value 
    runningTotalDev = ((rate[i] - runningTotalHRV)*(rate[i] - runningTotalHRV) + runningTotalDev); //make sum of squares of deviations
    //previousRunningTotalDev = runningTotalDev; //note running Total Dev = variance!
  }
    HRV_Value = sqrt(runningTotalDev/100);
    
  } 
}         

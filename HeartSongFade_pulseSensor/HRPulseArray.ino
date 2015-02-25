void HRPulseArray() {
  // keep a running total of the last 10 IBI values
  pulsetime = millis(); 
  IBI = pulsetime - lastpulsetime;        // measure time between beats in mS
  lastpulsetime = pulsetime;               // keep track of time for next pulse
  word runningTotal = 0;                  // clear the runningTotal variable    
  for(int i=0; i<=8; i++){                // shift data in the rate array
    rate[i] = rate[i+1];                  // and drop the oldest IBI value 
    runningTotal += rate[i];              // add up the 9 oldest IBI values
  }
  rate[9] = IBI;                          // add the latest IBI to the rate array
  if (rate[0] != 0){
    runningTotal += rate[9];                // add the latest IBI to runningTotal
    runningTotal /= 10;                     // average the last 10 IBI values 
    BPM = 60000/runningTotal;               // how many beats can fit into a minute? that's BPM!
  } 
} 


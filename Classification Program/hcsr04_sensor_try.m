function hcsr04_sensor_try()
oR=raspi('169.254.29.168','pi','raspberry');

trig=23;
echo=24;
configurePin(oR,trig,'DigitalOutput');
configurePin(oR,echo,'DigitalInput');

writeDigitalPin(oR,trig,0);
fileID=fopen("sample.txt","w+");
i=0;
while i<1000
    writeDigitalPin(oR,trig,0);
    pause(2);
    writeDigitalPin(oR,trig,1);
    pause(10e-5);
    writeDigitalPin(oR,trig,0);
    
    start=tic;
    while readDigitalPin(oR,echo)==0
        continue;
    end
    while readDigitalPin(oR,echo)==1
        continue;
    end
    duration=toc(start);
    distance=(duration*17150);
    distance=distance/2;
    fprintf(fileID,"Jarak = %f \n",distance);
    i=i+1;
end
fclose(fileID);
end
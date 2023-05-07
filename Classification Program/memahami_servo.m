function memahami_servo()

my_pi=raspi();
s=servo(my_pi,12,'MinPulseDuration',1e-3, 'MaxPulseDuration',2e-3);

writePosition(s,90);
pause(1);

i=0;

%Initial Sensor Position = 90
%Posisi Untuk Organik = 0
% Posisi Untuk Anorganik = 180

while i<5
    writePosition(s,90);
    pause(1);
    %sprintf("Servo Position = %f\n",readPosition(s));
    writePosition(s,180);
    pause(1);
    %sprintf("Servo Position = %f\n",readPosition(s));
    writePosition(s,90);
    pause(1);
    break;
    i=i+1;
end

writePosition(s,90);

end
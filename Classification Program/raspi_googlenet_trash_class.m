function raspi_googlenet_trash_class()
%Inisiasi Model Dan Sebagainya
raspiObj=raspi();
cam=webcam(raspiObj,2,'320x240');
%cam=cameraboard(raspiObj,'Resolution','1920x1080');
%Init a servo and its initial position
s=servo(raspiObj,12,'MinPulseDuration',1e-3, 'MaxPulseDuration',2e-3);
writePosition(s,90);
pause(1);
net=coder.loadDeepLearningNetwork('Googlenet_Trained_Network.mat','Googlenet_Trained_Network');
ukuran=[224 224];
to_show='.....';
start=tic;
PUSH_BUTTON=20; 
while true
    img=snapshot(cam);
    el_time=toc(start);
    tic
    if el_time>1
        IMG=imresize(img,ukuran);
        [label,score]=net.classify(IMG);
        label=cellstr(label);
        score=max(score);
        action="Tidak Buang";
        action=cellstr(action);
        %fps=cellstr(fps);
        %avgfps=cellstr(avgfps);
        %to_show=sprintf('Label : %s \n Score : %f \n Action : %s',...
            %label{:},score,action{:});
        if readDigitalPin(raspiObj,PUSH_BUTTON)==1
            if strcmp(label,'Organik')
                writePosition(s,90);
                pause(1);
                writePosition(s,0);
                pause(1);
                writePosition(s,90);
                pause(1);
            end
            if strcmp(label,'Anorganik')
                writePosition(s,90);
                pause(1);
                writePosition(s,180);
                pause(1)
                writePosition(s,90);
                pause(1);
            end
        end
    end
    to_show=sprintf('Label : %s \n Score : %f \n Action : %s \n El Time : %f',...
            label{:},score,action{:},toc);
    img_label=insertText(img,[0 0],to_show);
    displayImage(raspiObj,img_label);
end
end
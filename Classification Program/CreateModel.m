%% Pemisah Sampah Organik dan Anorganik Berbasis CNN Yang Dijalankan di Raspberry Pi

loc="Dataset";
imds=imageDatastore(loc,'LabelSource',...
    'foldernames','IncludeSubfolders',1,...
    'FileExtensions',{'.png','.jpg','.jfif','.jpeg'});
%%
ukuran=[224 224 3];
[train,validate]=splitEachLabel(imds,0.9,'randomize');
train=augmentedImageDatastore(ukuran,train,'ColorPreprocessing','gray2rgb');
validate=augmentedImageDatastore(ukuran,validate,'ColorPreprocessing','gray2rgb');
%%
deepNetworkDesigner
%%
load Googlenet_Trained_Network.mat
load Googlenet_Info.mat
I=imread("Foto Uji/Sampah_Organik.jpeg");
I=imresize(I,[224 224]);
[c,s]=classify(Googlenet_Trained_Network,I);
c=string(c);
I1=imread("Foto Uji/Sampah_Anorganik.jpeg");
I1=imresize(I1,[224 224]);
[c1,s1]=classify(Googlenet_Trained_Network,I1);
c1=string(c1);
I2=imread("Foto Uji/Lingkungan_Bersih.jpeg");
I2=imresize(I2,[224 224]);
[c2,s2]=classify(Googlenet_Trained_Network,I2);
c2=string(c2);
%%
figure(1)
subplot(121)
imshow(I)
title(c)
subplot(122)
imshow(I1)
title(c1)
%%
figure(2)
plot(Googlenet_Trained_Network)
%%
%Load Hasil Pelatihan
TA=Googlenet_Info.TrainingAccuracy;
VA=Googlenet_Info.ValidationAccuracy;

TL=Googlenet_Info.TrainingLoss;
VL=Googlenet_Info.ValidationLoss;

figure(3)
subplot(211)
plot(TA,'b')
hold on
plot(VA,'-o')
hold off
legend("Training Accuracy","Validation Accuracy","Location","best")
title("Training Accuracy And Validation Accuracy")
subplot(212)
plot(TL)
hold on
plot(VL,'-o')
hold off
legend("Training Loss","Validation Loss","Location","best")
title("Training Loss And Validation Loss")
%%
board=targetHardware("Raspberry Pi");
board.CoderConfig.TargetLang="C++";
 
dlcfg=coder.DeepLearningConfig("arm-compute");
dlcfg.ArmArchitecture="armv7";
dlcfg.ArmComputeVersion="19.05"; 
board.CoderConfig.DeepLearningConfig=dlcfg;

deploy(board,'raspi_googlenet_trash_class');
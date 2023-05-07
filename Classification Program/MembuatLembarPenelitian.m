clc;clear;close all;

fil_o='/Volumes/Disk_File/For Learning/My Future Skripsi/Program Raspberry Pi/Classification Program/Gambar Data/Sampah Organik/';
fil_a='/Volumes/Disk_File/For Learning/My Future Skripsi/Program Raspberry Pi/Classification Program/Gambar Data/Sampah Anorganik/';

filo=dir(fil_o);
fila=dir(fil_a);

nga=zeros(33,1);
ngo=zeros(33,1);

for i=4:33
    nga(i-3,1)=fila(i+3).name;
end

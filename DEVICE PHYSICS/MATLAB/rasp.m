clc
clear
close all
data = importdata('voltageLog.txt');
charge(1:101,:)=data(1:101,:);
discharge(1:100,:)=data(102:end,:);
plot(charge(:,1),charge(:,2),'ro',discharge(:,1),discharge(:,2),'bo')
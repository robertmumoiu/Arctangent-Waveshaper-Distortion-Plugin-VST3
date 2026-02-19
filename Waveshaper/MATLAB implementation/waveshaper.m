clc; clear; close all; clear sound;

% fs = 44100;
% duration = 1;
fsin = 500;

gain = 0.75;
k_pos = 4;
k_neg = 7;
cascade = 2;
invert = 0;

% t = 0:1/fs:duration-1/fs; 
% input_signal = sin(2 * pi * fsin * t);

[input_signal, fs] = audioread("guitar1.wav")
duration = length(input_signal)/fs;
t = 0:1/fs:duration-1/fs;

output_signal = input_signal;

for s = 1:cascade
    pos = (output_signal >= 0);
    neg = (output_signal < 0);

    output_signal(pos) = 1/atan(k_pos) * atan(k_pos * output_signal(pos));
    output_signal(neg) = 1/atan(k_neg) * atan(k_neg * output_signal(neg));
    
    if invert
        output_signal = -output_signal;
    end

end

output_signal = output_signal * gain;

% analiza frecventa

fft_in = fftshift(fft(input_signal));
fft_out = fftshift(fft(output_signal));

N = length(fft_in);
f = -fs/2:fs/N:fs/2-fs/N; % am lasat de la -fs/2 la fs/2 pt simplitate, matlab ignora automat valorile negative pentru graficul semilogx

magn_in = abs(fft_in)/N;
magn_out = abs(fft_out)/N;

magn_in_db = 20 * log10(magn_in + 0.0001); % +0.0001 pt a evita warning de log(0)
magn_out_db = 20 * log10(magn_out + 0.0001);


figure;

% grafic timp
subplot(3, 1, 1);
plot(t, input_signal);
hold on;
plot(t, output_signal);
title('Grafic domeniu timp: intrare vs iesire')
xlabel('Timp (s)');
ylabel('Amplitudine');
grid on;

% grafic frecventa scara logaritmica
subplot(3, 1, 2);
semilogx(f, magn_in_db);
hold on;
semilogx(f, magn_out_db);
title('Grafic domeniu frecventa/spectru scara logaritmica');
xlabel('Frecventa (Hz)');
ylabel('Magnitudine (dB)')
grid on;

% spectru
subplot(3, 1, 3);
plot(f, magn_in_db);
hold on;
plot(f, magn_out_db);
title('Spectru');
xlabel('Frecventa (Hz)');
ylabel('Magnitudine (dB)')
grid on;

sound(input_signal, fs);
pause(duration);
sound(output_signal, fs);

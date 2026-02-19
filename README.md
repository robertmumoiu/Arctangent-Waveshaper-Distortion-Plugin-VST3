# Arctangent-Waveshaper-Distortion-Plugin-VST3
VST3 audio plugin, developed in C++ (using JUCE framework) that can be used in a DAW to apply a symmetrical/asymmetrical distortion effect to an audio file.
*Inspiration:* "Designing Audio Effect Plug-Ins in C++: With Digital Audio Signal Processing Theory" by Will Pirkle

<img width="502" height="281" alt="image" src="https://github.com/user-attachments/assets/fdb0aa35-3d01-46c7-9691-6dfd941df01c" />

## Components:
- Gain: basic gain/volume slider in dB, with range between -70.0 and 0
- K positive/negative: distortion factor for both positive and negative semialternating parts of the audio signal, with values going from 1 (clean - output signal is approximately equal to input signal) to 20 (heavy distortion)
- Stages: used to increase the sound density and consistency by cascading the signal through the waveshaper algorithm up to 10 times, imitating the effect of a class A amplifier circuit with multiple tubes
- Invert: toggle phase inversion (inverted signal, again imitating class A amp circuits)

## How it works:
  For the input signal x(n), we apply the formula for the output signal y(n):
    y(n) = 1/arctan(k) * arctan(k * x(n))
  The arctangent is a nonlinear function, part of the sigmoid family, that when applied to our input signal, turns its cycles into a "clipped" square-like wave as the distortion factor's value increases. We use the normalization factor 1/arctan(k) to restrict the output values between -1 and 1. 

## MATLAB implementation:
Before building the project, I implemented the waveshaping algorithm in MATLAB, in order to understand how it works and implement the design for the asymmetrical distortion, and to analyze the time domain graphic and frequency domain spectrum for the input and output values. 

## C++ implementation:
- Plugin Processor: the algorithm iterates through audio buffers sample by sample, applying the waveshaper formula, handling the stage casacading and inversion, while also saving the states of the plugin for use at a later time
- Plugin Editor: custom built graphical interface using the JUCE editor that implements functionalities for sliders (for gain, distortion factor, stages) and a button (for inversion), that are used to send data to the process block via user input.

## How to use:
- to use in a DAW, simply download the .vst3 file and add it to your DAW's VST3 plugin folder
- there is also an executable file in the "C++ implementations" folder that was created as a standalone plugin for debugging purposes, you can test it out by using your microphone as input

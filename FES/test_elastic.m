hip = linspace(-1.5,-1.5,100)
ankle = linspace(0,-0.5,100)
knee = linspace(0,-1.7,100)

M_H = exp(2.1080 - 0.0160*knee - 0.0195*hip) - exp(-2.1784 + 0.070*knee + 0.1349*hip) - 15.24;

M_K = exp(1.0372 + 0.0040*ankle - 0.0494*knee - 0.0250*hip)-...
      exp(-1.1561 - 0.0020*ankle + 0.0254*knee + 0.0030*hip)+...
      exp(2.5-0.25*knee) + 1.0;
% 
M_A = exp(2.0111 - 0.0833*ankle - 0.0090)-exp(-9.9250 + 0.2132*ankle) - 2.970;
hold on
plot(M_H)
plot(M_K)
plot(M_A)
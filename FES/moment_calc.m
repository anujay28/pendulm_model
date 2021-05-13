function [tau] = moment_calc(force,ma)
%MOMENT_CALC Summary of this function goes here
%   Detailed explanation goes here

  tau = [0;0;0];
  for ii = 1:3
      for jj = 1:9
          tau(ii) = tau(ii) + force(jj) * ma(jj,ii)
      end
  end
end


function vals=RMS_ALL(data)
%RMS_ALL
%
% The RMS_ALL function defines a custom requirement used in the
% graphical SDOTOOL environment.

% The |vals| return argument is the value returned to the SDOTOOL
% optimization solver.
%
% The |data| input is a structure with fields containing design variable
% values and logged simulation data. For example, if SDOTOOL is configured
% to optimize a design variable set |DesignVars| and the custom requirement
% configured to log a signal |Sig| the |data| structure has fields as
% follows:
%
% data.DesignVars    %Design variable values
% data.Nominal.Sig   %Logged signal when simulating model with |DesignVars|
%
% If SDOTOOL is configured to optimize with an uncertain variables set the
% |data| structure includes fields with logged signals when simulating the
% model with |DesignVars| and uncertain values
%
% data.Uncertain.Sig
%
% See the |sdoHydraulicCylinder_customObjective| function and the
% |sdoHydraulicCylinder_uidemo| for an example of a custom requirement
% function.
%


ref = data.Nominal.ref.Data;

human = data.Nominal.human.Data;
human = reshape(human',2,1,[]); % reshape magic
exo = data.Nominal.exo.Data;
ref_vel = data.Nominal.vel.Data;
exo_vel = data.Nominal.exo_vel.Data;




e_exo = ( exo - ref).^2;
exo_error = sqrt( sum(sum(e_exo,3)) / length(e_exo));

e_human =  ( human - ref).^2;
human_error = sqrt(sum(sum(e_human,3)) / length(e_human));


e_vel = ( exo_vel - ref_vel).^2;
vel_error = sqrt(sum(sum(e_vel,3)) / length(e_vel));



vals =  exo_error + human_error;% vel_error; %human_error +

end
function vals=myCustomRequirement(data)
%MYCUSTOMREQUIREMENT
%
% The myCustomRequirement function defines a custom requirement used in the
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
vel = data.Nominal.vel.Data;
exo = data.Nominal.exo.Data;
exo_vel = data.Nominal.exo.Data;
human = data.Nominal.human.Data;
human = reshape(human',2,1,[]); % reshape magic

e_ref = sqrt(( human - ref).^2);
e_vel = sqrt(( vel - exo_vel).^2);
e_human = sqrt( ( exo - ref).^2);
joint_error = sum(e_ref,3) %+ sum(e_human,3) %+ sum(e_vel,3);
vals = sum(joint_error);

end
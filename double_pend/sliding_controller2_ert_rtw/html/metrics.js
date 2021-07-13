function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtInf"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	size: 8};
	 this.metricsArray.var["rtInfF"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	size: 4};
	 this.metricsArray.var["rtMinusInf"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	size: 8};
	 this.metricsArray.var["rtMinusInfF"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	size: 4};
	 this.metricsArray.var["rtNaN"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	size: 8};
	 this.metricsArray.var["rtNaNF"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	size: 4};
	 this.metricsArray.fcn["rtGetInf"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rtGetInf.cpp",
	stack: 34,
	stackTotal: 34};
	 this.metricsArray.fcn["rtGetInfF"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rtGetInf.cpp",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetMinusInf"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rtGetInf.cpp",
	stack: 34,
	stackTotal: 34};
	 this.metricsArray.fcn["rtGetMinusInfF"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rtGetInf.cpp",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetNaN"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rtGetNaN.cpp",
	stack: 34,
	stackTotal: 34};
	 this.metricsArray.fcn["rtGetNaNF"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rtGetNaN.cpp",
	stack: 10,
	stackTotal: 10};
	 this.metricsArray.fcn["rtIsInf"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsInfF"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaN"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	stack: 27,
	stackTotal: 27};
	 this.metricsArray.fcn["rtIsNaNF"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rt_InitInfAndNaN"] = {file: "/home/nathanielgoldfarb/pendulm_model/double_pend/sliding_controller2_ert_rtw/rt_nonfinite.cpp",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="sliding_controller2_metrics.html">Global Memory: 36(bytes) Maximum Stack: 34(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();

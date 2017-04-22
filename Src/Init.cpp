#include "avisynth.h"
#include "conditional.h"

AVSValue __cdecl Create_ConditionalFilterMT(AVSValue args, void* user_data, IScriptEnvironment* env) {
	return new ConditionalFilter(args[0].AsClip(), args[1].AsClip(), args[2].AsClip(), args[3], args[4], args[5], args[6].AsBool(false), env);
}

const AVS_Linkage *AVS_linkage = 0;

extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit3(IScriptEnvironment* env, const AVS_Linkage* const vectors) {
	AVS_linkage = vectors;
	env->AddFunction("ConditionalFilterMT", "cccsss[show]b", Create_ConditionalFilterMT, 0);
	return "ConditionalFilterMT";
}

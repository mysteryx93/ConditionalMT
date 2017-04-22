# ConditionalMT - v1.0
Avisynth conditional functions that work with MT

by Etienne Charland

[Avisynth+ MT](https://forum.doom9.org/showthread.php?t=168856) provides great capabilities to process videos. However, conditional functions are
not compatible with MT (multi-threading) due to design limitations. To work around this problem,
this class provides a subset of conditional features that will work with MT mode.

Currently supported:
- [ConditionalFilter](http://avisynth.nl/index.php/ConditionalFilter)

Example: this will apply blur to all frames with AverageLuma < 50
```
LoadPlugin("ConditionalMT.dll")
vid = AviSource("Source.avi")
vid_blur = vid.Blur(1.5)
ConditionalFilterMT(vid, vid_blur, vid, "AverageLuma", "lessthan", "50")
Prefetch(4)
```

All the standard function expressions are supported. However, only a single plain function name is supported -- no expression.
Do not include parenthesis.
- AverageLuma
- AverageChromaU
- AverageChromaV
- RGBDifference
- LumaDifference
- ChromaUDifference
- ChromaVDifference
- YDifferenceFromPrevious
- UDifferenceFromPrevious
- VDifferenceFromPrevious
- RGBDifferenceFromPrevious
- YDifferenceToNext
- UDifferenceToNext
- VDifferenceToNext
- RGBDifferenceToNext
- YPlaneMax
- YPlaneMin
- YPlaneMedian
- UPlaneMax
- UPlaneMin
- UPlaneMedian
- VPlaneMax
- VPlaneMin
- VPlaneMedian
- YPlaneMinMaxDifference
- UPlaneMinMaxDifference
- VPlaneMinMaxDifference

Functions comparing two clips will compare testclip with source1. Some functions have treshold and offset parameters. 
These parameters are not currently supported and are left at 0. If you need them, feel free to edit the code to parse parameter values.

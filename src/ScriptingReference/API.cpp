/**
 * @addtogroup API
 * PlugNScript Application Programming Interface
 * Functions and variables defined by the C++ scripting host
 * Do not include this file in your scripts: it is provided
 * for documentation purposes only. Classes and functions are already made available
 * to scripts by the plug-in.
 * Created by Blue Cat Audio <services@bluecataudio.com>
 * Copyright 2011-2017 Blue Cat Audio. All rights reserved.
 *
 * @{
 */

/// The number of audio inputs of the dsp filter
const uint audioInputsCount;
/// The number of audio outputs of the dsp filter
const uint audioOutputsCount;
/// The number of (optional) auxiliary audio inputs of the dsp filter
const uint auxAudioInputsCount;
/// The number of (optional) auxiliary audio outputs of the dsp filter
const uint auxAudioOutputsCount;

/// The maximum number of samples per block for block processing.
const int maxBlockSize;
/// The current sample rate.
const double sampleRate;

/// The path to the user documents folder on the file system
/// (Using '/' separators)
const string userDocumentsPath;

/// The path of the current dsp script file on the file system
/// (Using '/' separators)
const string scriptFilePath;

/// The path of the current dsp script data folder in the file system,
///  where additional file resources can be stored ("scriptname-data")
/// (Using '/' separators)
const string scriptDataPath;

/** MIDI Event (packet) abstraction.
* Contains 4 bytes of data and a timestamp.
*/
class MidiEvent
{
    /// MIDI data (4 bytes packet)
    uint8 byte0;
    uint8 byte1;
    uint8 byte2;
    uint8 byte3;
    /// time stamp of the event, as an offset in samples
    /// from the beginning of the current block.
    double timeStamp;
};

/** List of MIDI Events.
*
*/
class MidiQueue
{
    /// Returns the number of events available in the queue.
    /// Accessed as "length" attribute.
    uint             get_length()const;
    /// Sets the number of events in the queue.
    /// Accessed as "length" attribute.
    void             set_length(uint l);
    /// [] operator: returns the Midi event located at index i in the queue.
    MidiEvent&       opIndex(uint i);
    /// [] operator: returns the Midi event located at index i in the queue.
    const MidiEvent& opIndex(uint i)const;
    /// pushes "evt" at the end of the events queue.
    void             push(const MidiEvent & evt);
};

/** Host Transport information.
*
*/
class TransportInfo
{
    /// Returns the current tempo (beats per minute)
    /// Can be accessed directly as "bpm" attribute.
    double  get_bpm()const;
    /// Returns the upper value of the time signature.
    /// Can be accessed directly as "timeSigTop" attribute.
    uint    get_timeSigTop()const;
    /// Returns the lower value of the time signature.
    /// Can be accessed directly as "timeSigBottom" attribute.
    uint    get_timeSigBottom()const;
    /// Returns true when the host application is playing.
    /// Can be accessed directly as "isPlaying" attribute.
    bool    get_isPlaying()const;
    /// Returns true when the transport of the host application is in a loop.
    /// Can be accessed directly as "isLooping" attribute.
    bool    get_isLooping()const;
    /// Returns true when the host application is recording.
    /// Can be accessed directly as "isRecording" attribute.
    bool    get_isRecording()const;
    /// Returns the position in samples of the first sample of the current
    /// buffer since the beginning of the song.
    /// Can be accessed directly as "positionInSamples" attribute.
    int64   get_positionInSamples()const;
    /// returns the position in quarter notes of the first sample of the
    /// current buffer since the beginning of the song.
    /// Can be accessed directly as "positionInQuarterNotes" attribute.
    double  get_positionInQuarterNotes()const;
    /// Returns the position in seconds of the first sample of the current
    /// buffer since the beginning of the song.
    /// Can be accessed directly as "positionInSeconds" attribute.
    double  get_positionInSeconds()const;
    /// Returns the position in quarter notes of the first bar of the current measure.
    /// Can be accessed directly as "currentMeasureDownBeat" attribute.
    double  get_currentMeasureDownBeat()const;
    ///  When looping, returns the position in quarter notes of the beginning of the loop.
    /// Can be accessed directly as "loopStart" attribute.
    double  get_loopStart()const;
    /// When looping, returns the position in quarter notes of the end of the loop.
    /// Can be accessed directly as "loopEnd" attribute.
    double  get_loopEnd()const;
};

/** Structure passed to the script for block processing.
*
*/
class BlockData
{
    /// An array containing audio buffers of each audio channel for this block.
    /// You can access sample i of channel ch using samples[ch][i].
    array< array<double> >@ samples;
    ///< The number of audio samples to process for this block.
    uint                    samplesToProcess;
    /// The incoming MIDI events queue.
    const MidiQueue@        inputMidiEvents;
    /// The MIDI events output queue to send MIDI events.
    MidiQueue@              outputMidiEvents;
    /// The input parameters values at the beginning of the block.
    const array<double>@    beginParamValues;
    /// The input parameters values at the ends of the block.
    const array<double>@    endParamValues;
    /// Transport information - may be null if not supported or provided
    /// by the host application.
    const TransportInfo@    transport;
};

/// Utility function that prints the content of a string to the log file.
void print(const string& in message);

/// Additional math function that produces a pseudo random number ranging
/// from min to max
double rand(double min = 0, double max = 1)

/// Additional string functions that can be used to convert data without allocating memory
/// They have the exact same behavior as their standard counterpart in Angelscript
void intToString(int64 val, string& ioString, const string &in options = "", uint width = 0);
void uIntToString(uint64 val, string& ioString, const string &in options = "", uint width = 0);
void floatToString(double val, string& ioString, const string &in options = "", uint width = 0,
                   uint precision = 0);

/// @}

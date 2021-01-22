/**
 * @addtogroup ScriptReference
 * Blue Cat PlugNcript Scripting Reference.
 * Shows functions and attributes that can be defined by the dsp script.
 * Do not include this file in your scripts: it is provided only
 * for documentation purposes.
 * You can however use it as a starting point to write your own scripts.
 * All methods and attributes are optional and can be ignored.
 * You can for example write a script with just a single function defined.
 * Created by Blue Cat Audio <services@bluecataudio.com>
 * Copyright 2011-2019 Blue Cat Audio. All rights reserved.
 *
 * @{
 */

// Script metadata----------------------------------------
/// The name of the script to be displayed in the plug-in.
string name = "Script Name";
/// The short description of the script to be displayed in the plug-in.
string description = "Script Description";

// Script I/O parameters and strings and associated metadata----------
/// An array of parameters to be used as input for the script.
/// Will be displayed in the user interface of the plug-in and accessible for
/// automation and MIDI control.
array<double> inputParameters(2);
/// Names to be displayed in the plug-in for the input parameters.
array<string> inputParametersNames = {"P1", "P2"};
/// Units for the corresponding input parameters.
array<string> inputParametersUnits = {"dB", "%"};
/// Enumeration values for the corresponding input parameters.
/// Array of strings containing semicolon separated values. Use empty strings
/// for non-enum parameters. Require that min and max values are defined.
array<string> inputParametersEnums = {"value1;value2", ""};
/// Value formatting for the corresponding input parameters.
/// Follows the same rules as floating point values formatting for the C "printf" function
array<string> inputParametersFormats = {".0", "+.2"};
/// Minimum values for the corresponding input parameters. Default value is 0.
array<double> inputParametersMin = {0, 0};
/// Maximum values for the corresponding input parameters. Default value is 1.
array<double> inputParametersMax = {10, 20};
/// Default values for the corresponding input parameters. Default value is 0.
array<double> inputParametersDefault = {5, 0};
/// Number of steps for the corresponding input parameters.
/// Default is -1 (continuous control - no steps).
array<int>    inputParametersSteps = {10, 20};

/// An array of strings to be used as input for the script.
/// Will be displayed in the user interface of the plug-in
array<string> inputStrings(2);
/// Names to be displayed in the plug-in for the input strings.
array<string> inputStringsNames = {"S1", "S2"};

/// An array of parameters to be used as output of the script.
/// Will be displayed in the user interface of the plug-in as meters and accessible
/// to generate automation and MIDI controllers.
array<double> outputParameters(2);
/// Names to be displayed in the plug-in for the output parameters.
array<string> outputParametersNames = {"OUT 1", " OUT 2"};
/// Units for the corresponding output parameters.
array<string> outputParametersUnits = {"dB", "dB"};
/// Enumeration values for the corresponding output parameters.
/// Array of strings containing semicolon separated values. Use empty strings
/// for non-enum parameters. Require that min and max values are defined.
array<string> outputParametersEnums = {"value1;value2", ""};
/// Value formatting for the corresponding output parameters.
/// Follows the same rules as floating point values formatting for the C "printf" function
array<string> outputParametersFormats = {".0", "+.2"};
/// Minimum values for the corresponding input parameters. Default value is 0.
array<double> outputParametersMin = {0, 0};
/// Maximum values for the corresponding input parameters. Default value is 1.
array<double> outputParametersMax = {10, 20};
/// Default values for the corresponding input parameters. Default value is 0.
array<double> outputParametersDefault = {5, 0};

/// An array of strings to be used as output for the script.
/// Will be displayed in the user interface of the plug-in
array<string> outputStrings(2);
/// Names to be displayed in the plug-in for the input strings.
array<string> outputStringsNames = {"S1", "S2"};
/// Maximum length for the ouput strings (output strings must be pre-allocated
/// to avoid audio dropouts).
array<int> outputStringsMaxLengths = {1024, 1024};

/** Initialization: called right after the script has been compiled
*   and before any other processing occurs.
*   Ignored if the initialize function returning a boolean is defined.
*/
void initialize()
{
}

/** Initialization: called right after the script has been compiled
*   and before any other processing occurs.
*   return false if initialization fails (for example if the number of
*   audio channels or the sample rate are not compatible).
*   When returning false, it is strongly advised to print a message with
*   the "print" function for the end user.
*/
bool initialize()
{
    /// write script initialization here
    /// and return false if something is not supported (number of channels, sample rate...)
    return true;
}

/** Reset the state of the filter.
*
*/
void reset()
{
}

/** Returns the tail size in samples.
*   use -1 for infinite (typically for audio or MIDI generators or synths).
*   use 0 if the processor does not produce any sound when fed with silence (default).
*/
int getTailSize()
{
    return 0;
}

/** Returns the latency added by the script if any, in samples.
*   Returns 0 by default.
*/
int getLatency()
{
    return 0;
}

/** Per-sample processing function: called for every sample with updated parameters values.
*   If defined, the processBlock function is ignored.
*   ioSample: an array of current audio samples (one element for each audio channel).
* You can access the current sample of channel 'ch' using ioSample[ch].
*/
void processSample(array<double>& ioSample)
{
}

/** Update internal parameters from inputParameters array when required.
*   Called every sample, right before the processSample() method, or every block,
*   before the processBlock() method.
*   This function will not be called if input parameters have not been modified since last call.
*/
void updateInputParameters()
{
}

/** Per-block processing function: called for every block with updated parameters values.
*   Ignored if the processSample() function is defined.
*/
void processBlock(BlockData& data)
{
}

/** Called for every block to update internal parameters from the inputParameters and
*   inputStrings arrays that have been updated by the host.
*   This function will not be called if input parameters have not been modified since last call,
*   and if transport info (tempo and time signature only) are unchanged.
*/
void updateInputParametersForBlock(const TransportInfo@ info)
{
}

/** Update output parameters values array from internal variables.
*
*/
void computeOutputData()
{
}

/// @}
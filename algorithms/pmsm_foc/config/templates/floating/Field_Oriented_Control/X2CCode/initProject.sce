// Script to initialize the project.
//
// Copyright (c) 2014, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
// All rights reserved.
//
// This file is licensed according to the BSD 3-clause license as follows:
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the "Linz Center of Mechatronics GmbH" and "LCM" nor
//       the names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL "Linz Center of Mechatronics GmbH" BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// $LastChangedRevision: 844 $
//
// This file is part of X2C. http://www.mechatronic-simulation.org/

// get file separator
fs = filesep();

// get current directory
CurrentDir = pwd();

// get system architecture
arch = getArchitecture();

if (getos() == "Linux") then
    // load X2C libraries (needed for simulation)
    loadLibs();
end

// get project directory (assumption: initProject.sce lies in X2CCode directory)
ProjectPath = strsubst(CurrentDir, "X2CCode", "");

mprintf("+ Initializing project\n")

// add Project specific library
chdir(ProjectPath);
x2c_setCurrentWorkingDir()
if isdir(ProjectPath + "Library") then

    jimport("at.lcm.x2c.core.librarymanager.X2cLibraryManager");
    x2cLM = jinvoke(X2cLibraryManager,"getInstance");
    x2cLibs = jinvoke(x2cLM, "addPath_XcosLibPathStr", ProjectPath + "Library");
    libRoot = [ProjectPath + "Library"];
    for curLib = x2cLibs
        chdir(curLib);
        libName = strsubst(curLib, [fs + "Scilab"], "");
        libName = strsubst(libName , [libRoot + fs], "");

        // load library
        loaderFile = ["loader_" + arch + ".sce"];
        if isfile(loaderFile) then
            exec(loaderFile, -1)
        end
        // load functions and palette
        //deletefile(libName + ".xpal");  // delete palette to force rebuild (otherwise error would occur since block image can't be found)
        exec("starter.sce", -1)

        mprintf("Project specific library " + libName + " added.\n")
    end
    chdir(CurrentDir)
    // clean  up
    clear("libName", "libRoot", "loaderFile", "curLib", "x2cLibs", "x2cLM")
    //mprintf("Project specific library " + libName + " added.\n")
end

// load model parameters
chdir(CurrentDir);

if isfile("ModelParameters.sce") then
    exec("ModelParameters.sce", -1);
    mprintf("Model parameter loaded.\n")
end

// clean up
clear("fs", "CurrentDir", "vers", "opt", "arc", "ProjectPath")
mprintf("- Init done and opening model...\n");
xcos("Model.zcos");

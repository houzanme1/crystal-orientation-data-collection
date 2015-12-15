# Introduction #
## Purpose ##
The purpose of this document is to describe the processes for capturing data and metadata as defined by the “Crystal Orientation Data Capture for Conversion to a General Data Type” project, including:
  * Processes for capturing data and metadata from instruments;
  * Metadata schema; and
  * Locations of information.

## Project Objective ##
The Federal Government, via the Australian National Data Service (ANDS), has funded the creation and development of the Australian Research Data Commons (ARDC) infrastructure, supporting the discovery of, and access to, research data held in Australian universities, publicly funded research agencies and government organisations for the use of research. Under this program, funding is available for Data Capture projects which create infrastructure within institutions to collect and manage data, and to improve the way metadata about it is managed.

Deakin University has been awarded funding under the “Data Capture” initiative for theANDS - Crystal Orientation Data Collection for Conversion to a General Data Type project.

The primary objective of this project is to develop infrastructure within Deakin’s electron microscope facility to support the ongoing data capture and management of metals deformation data and metadata, supporting the discovery, reuse and sharing of this research data by other researchers into the future.

This project will also utilise infrastructure developed by the ANDS –Seeding the Commons project for metadata storage and harvest.

## Background ##
As part of Deakin’s ANDS Seeding the Commons Project (SC19), the potential solution options for storage and capture of research metadata were reviewed and the following recommendations made.
  * The Deakin Research Online (DRO) publications and publications metadata repository would be used as the repository for research data collection metadata. The DRO will be enhanced as part of the ANDS Seeding the Commons Project (SC19) in order to support the capture, management, storage and harvest of research metadata.
  * Deakin’s research metadata would be captured and stored independently of the existing publications metadata, allowing customisation of the metadata captured for research compared with the metadata captured for publications. However, enhancements would be made to the DRO to ensure searching functionality would allow searching of both publications and research metadata in an integrated manner.
  * Deakin’s research metadata would be captured and stored in a customised Deakin Metadata schema, supporting the capture of all metadata fields required for submission to ANDS (as defined by the RIF-CS standard), plus additional metadata fields identified as required for Deakin’s own use.The Deakin Metadata schema will be defined as part of the ANDS Seeding the Commons Project (SC19).
  * Deakin’s research data collections would not be stored in the DRO due to limitations on space that may impact data collections which generate large data files, such as high-resolution images.
  * Deakin’s research data collections will be stored within the faculties in which they are generated. The Crystal Orientation Data Capture project will pilot the use of Deakin’s existing ISILON shares, which are supported by ITSD and provide secure, backed-up storage, for the storage of research data collections. The ISILON shares are web-enabled, supporting direct access via the DRO to data collections which have been released for open access. (Deakin Research Services Division and ITSD are currently seeking funding for the development of a Research Data Management Plan which will determine the long-term strategy for storage of research data at the University.)
  * Deakin Research Online (DRO) provides existing functionality which supports the control, authorisation and publication of research metadata, and will provide a portal for direct or mediated access to the research data collections.

These recommendations were accepted by the Project Board and form the basis for the software architecture for the Crystal Orientation Data Capture system, and for the processes based on this architecture for the capture of data and metadata.

## What will this software do ##

This software will working together with the existing microscope equipment and acquisition software within the Electron Microscope Facility, including but not limited to
  * SEM -  HKL Conversion Process
  * SEM - TSL-OIM Conversion Process
  * TEM -NanomegasDigistar Conversion Process

This software will collect, standardise and convert electron diffraction data and metadata from each different acquisition system, then transfer to a centralised data storage. The acquired data will be organised into a project and session basis.

## What will this software not do ##

This software does not have the knowledge of research activity itself. It will not operate the microscope equipment or replace the acquisition software. This software will not interrupt the research activities either.


# Installation and Configuration #
Target Audience: System Administrator, Research Project Leader

## Install the Software ##

The install package is downloadable from http://code.google.com/p/crystal-orientation-data-collection.

## System Requirement ##
  * Intel  1.3GHz or faster processor
  * Microsoft  Windows  XP Home, Professional, or Tablet PC Edition with Service Pack 3 (32 bit) or Service Pack 2 (64 bit); Windows Server  2003 (with Service Pack 2 for 64 bit; Windows Server2008 (32 bit and 64 bit); Windows Server 2008 [R2](https://code.google.com/p/crystal-orientation-data-collection/source/detail?r=2) (32 bit and 64 bit); Windows Vista  Home Basic, Home Premium, Business, Ultimate, or Enterprise with Service Pack 2 (32 bit and 64 bit); Windows 7 or Windows 7 with Service Pack 1 Starter, Home Premium, Professional, Ultimate, or Enterprise (32 bit and 64 bit)
  * 256MB of RAM (512MB recommended)
  * 100MB of available hard-disk space
  * 1024x786 screen resolution recommended
  * Microsoft Internet Explorer 7, 8, 9; Firefox 3.6, 4.0 or 6.0; Chrome
  * Video hardware acceleration (optional)

## Installation ##

There are several packages available on http://code.google.com/p/crystal-orientation-data-collection/downloads. Always download and install the latest version.

The easiest way to install is to download the all-in-one installation package and extract to your local drive. The all-in-one installation package delivers all required binary files, dependencies and sample configuration files.

For advanced installation options, this software is distributed in 2 component installation packages:
  * Dependency-Package
> > This package contains the fundamental files required by this software. These files are reused in all versions
  * Execute-Binary
> > The execute binary files comes in this package. This package has a faster release frequency.

To perform a complete installation, download both packages on the latest version, then extract to the same folder. It is highly recommended to install this software in folder C:\DC20A

After installation, this software is required to start when system is started up.

## Get the Network Storage Ready ##

Before acquire and transfer data with this software, make sure the Network Storage is setup properly.

A dedicated network storage service is required for data storage and discover via Server Message Block (SMB), also known asCommon Internet File System (CIFS) Protocol. By default each research project will have a corresponding folder in this storage service. The project folders should be assigned a name representing the project ID or short name.

You may indicate a particular sub-folder as the default path for research data transfer. All research data will go into this sub-folder.

This software will try to look for a project definition in your appointed sub-folder. The definition needs to be stored in a file named “PROJECT.ini”. Within this file these definition items are expected.
| Item | Description |
|:-----|:------------|
| `[project`] project.name	| The project name |
| `[project`] project.owner | Project leader and contact information |
| `[metadata`]	| Assign technical metadata to this project. These metadata will be collected at the beginning of each research activity. |

Project folders and project definition files should be setup prior the research activity.

All research data acquired during a research activity, as well as the technical metadata, will be organised into one single folder. These are named Session Folders on the network storage. Each Session Folder will be assigned a unique name representing the timestamp when the activity conducted. The session folders will be created automatically.


When setup completed, the network storage is ready to receive research data.

## Software Configuration ##

A configuration file will be loaded from path config\default.ini by default. You may store your configuration file anywhere on local driver, then pass on to this software via command line parameters.

Set up these items in your configuration file:

|Item	| Description |
|:----|:------------|
|sys.encryption.salt |	A random string to encrypt your password |
|sys.network.enabled |		Enable (1) or disable (0) network storage |
|sys.network.smb.service	 |	The SMB service path, like //host/service |
|sys.network.smb.username	 |	Username to access SMB storage |
|sys.network.smb.password	 |	Encrypted Password |
|sys.network.smb.domain	 |	The workgroup for SMB storage |
|sys.network.smb.storage	 |	The default path to store data on the SMB. Variable %PID% will be replaced by project id, %SID% for the session id. For example %PID%/upload |
|sys.network.checking.interval |		Time interval to update connection status (in seconds) |
|sys.utils.smbclient.program	 |	The path to smbclient tool |

## Instrument and Acquisition Software Setup ##

Your research instrument needs to be supported before research data is acquired by this software.
After installation, these instruments and microscope software are supported automatically
  * SEM -  HKL Conversion Process
  * SEM - TSL-OIM Conversion Process
  * TEM - NanomegasDigistar Conversion Process

Your instrument may already been supported and there may already be downloads available for your instrument. Check http://code.google.com/p/crystal-orientation-data-collection/wiki/EquipmentSupported for your instrument.

If your instrument and microscope software is supported, download the scripts then extract to installation folder, for example C:\DC20A. You also need to follow the integration instructions for the configuration of your instrument and acquisition software.

If not supported, you can always create a script file to enable your acquisition software complying with integration standard. Refer to Extending (TODO: Put the Section Link Here)section for script construction and induction. You are always encouraged and welcomed to add your instrument scripts to list and share with other users.

# Software Usage #
Target Audience: Software User, Researcher

## Start the Software ##
This software will run automatically when your windows operation system is started. If not, contact your system administrator for a propersetting.

When the software is started, a Main Window will show on screen, as following

![http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-main-dialog.png](http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-main-dialog.png)

This Main Window shows the system logs. System logs are also stored on local hard drive.

Setting label: Click on this label to edit the configuration.

> Note: Consult your system administrator before making any change. The change will take effect after system reboot.

Clear label: Clear all logs displayed in Main Window.
> Note: This will not clear the system log stored on local drive.

Close button: Hide the main window but keep this software running in background.

An icon will be displayed in system tray.

![http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-notify-icon.png](http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-notify-icon.png)

Double click on the icon to show or hide the main window. Right click on this icon will pop up a system menu.

> ![http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-popup-menu.png](http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-popup-menu.png)

Restore Console: Display the main window.
Hide Console: Hide the main window from screen. This software will continue running in background.
Exit: Stop running and exit.
## Start a New Research Session ##

![http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-new-session-dialog.png](http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-new-session-dialog.png)

To conduct a research activity, user needs to start a new research session.

If your system has been configured properly, a new research session could always be started by double clicking the shortcut on Desktop or from the Start Menu.

For advanced users, new research session can also be started from command line, with parameters as following:

`-c --config-file CONFIG_FILE_PATH`

Optional.Use the defined configuration file. If not specified, will use file config\default.ini

`-e --equipment-id EQUIPMENT_ID`
Optional. Start the specific research equipment. If not specified or invalid, appoints the first definition of research equipment ID by default.

Sample commands
`CRYSTOSoftware.exe --config-file default.ini --equipment-id HKL`
`CRYSTOSoftware.exe -c default.ini -e HKL`

The request to start a research session will be confirmed via a dialog, as following

User needs to specific a research project the new research session associated with, and provides required metadata before the session is started.

Research Project: Select which project is associated with the new research session.
> Note: For those sessions with no research project associated, choose the “-Not a registered research project-“option from the dropdown list. In this case, research data may be produced by your microscope equipment, but not acquired, processed or stored by this software.
Metadata: Provide required technical metadata if a project is specified.
Cancel button: Do not start a new research session and hide this dialog.
Start button: Launch the specific acquisition software to operate microscope instrument.

After clicking on the Start button, you will interact with the microscope acquisition software. The research data produced during your session will be monitored.

## Import Your Project ##
Since version 2.0 if your project is not listed in the new session window, you can add your project to be included by importing project and creating a project profile.

To Add a new project to the list in "Start a new session" window, click on the "`Project Not Found?`" link, as shown below.

![http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-import-project-dialog.png](http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/screen-import-project-dialog.png)

This dialog will show all the project folders existing on your central data storage but without a project profile (PROJECT.ini file).

To import a project, select from the drop down list, then type in the required information in matrix underneath.

You can also define required technical metadata. Simply enter the metadata name in **Name** column, then provide default value, or any type of text as a hint in **Value** column.

When you finish editing, click on "Apply" button to create a project profile. The project profile will be uploaded to your centralised data storage and Synchronised to other CRYSTOSoftware clients.

Note: To upload project profile to your centralised data storage, the project data folder should already be created and configured to assign write permission for your account.

Note: The project data folder is defined in your configuration file, with a name of `sys.network.smb.storage`

## Export data ##
When your research activity is completed, your data may be exported from binary format to a text-based format. This is an automatic procedure and requires no interaction.
The export of data is configured in your instrument and acquisition software settings.

## Processing data ##
Your data may also been processed by a third-party program. For instance, converting or standardising to common format, or enhancing the quality. This is an automatic procedure and no interaction required.
The processing of data is configured in your instrument and acquisition software settings.

## Transferring Data to Network Storage ##
After each session, all your data will be transferred automatically to the network storage. The transfer will include raw produced by instrument, exported data as well as processed data. A text file will also be created to record information for your current session. This file will be stored in the Session Folder with the name “METADATA.ini”.
> Note: If you choose the “-Not a registered research project-“ option when starting this session, your data will not be transferred.
You will still have your research data on local drive. Remove or delete data from your local drive will not affect the data already stored on network storage.
For the path of your research data, please consult your system administrator.
When data transfer is completed, this software will idle and get ready for the next research activity.
# Internal Process and Workflow #
Target Audience: Software User, Researcher, Software Developer

## Equipment, Project & Session ##
This software defines Equipment, Project and Session.

### Equipment ###
Equipment is defined as the specific knowledge related to research instrument and the associated software for data acquisition and processing.
This software needs to be aware of,
  * name of the instrument associated software
  * how to start the instrument associated software
  * what data format will be produced during acquisition, where to find them
  * what is the finishing flag of the data acquisition
  * shall the data be exported to another format
  * shall the data need further customised process
  * shall the data be transferred to network storage
Equipment is defined in the configuration file. A list of supported equipments is available on http://code.google.com/p/crystal-orientation-data-collection/wiki/EquipmentSupported

### Project ###
A Project consists of a series of research activities. A Project may define a list of technical metadata and give a default value for each.
Project information is updated automatically on a daily basis. This software will look for a file with name “PROJECT.ini” in the Project folder on server.

### Session ###
Session is defined as a research activity. A Session will involve Equipment as source of data, and attach the research to a specific Project.
If the Project has technical metadata defined, the researcher operating the instrument will be requested for the parameters of each item, at the very beginning of a session. A session will also record a list of data files to be transferred to network storage, including raw research data and any data files generated after further process.
A Session exchange file is created during the activity. It is then uploaded to the session folder on network storage with a name “METADATA.ini”, together with all data files acquired during the session.

## Internal Process ##
Several data streams are working together within this software.
  * Project Update
> > This data stream will synchronise the project definitions from network server. This software will look for “PROJECT.ini” in each project folder.
> > Synchronisation happens every 24 hours. If no project definition stored on local, the synchronisation will happen immediately when this software is started.
  * Data Acquisition and Processing
> > When researcher started this software with an Equipment parameter, this software will start the instrument associated software and record all new data files generated during the research session. Data files will be exported and customised to expected format. A file list of these new data files will be produced in the session exchange file. When the data acquisition and processing completed, the session will be queued for data transfer.
> > If supported, this software will export the raw research data acquired during the session to a particular format. This software will utilise the instrument associated software to perform this action. As per the configuration, this software may simulate keyboard and mouse operations to interact with the instrument software.
> > Some equipment may also be configured to have the data processed with a customised processing program. For instance, the data may be converted to another format, or be enhanced for better quality. The processing program is a customised tool and not necessarily from the instrument vendor.
> > By default, this software will be installed with a data conversation tool which works on .ang files and convert to .ctf format, or the reverse.
  * Data Transferring to Network Storage
> > This data stream will start immediately when this software started. This data stream will work on a queue of session exchange files. For each session, the list of research data file, as well as the research exchange file itself will be transferred to network storage.


## Workflow ##
The life span of each internal process component

![http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/workflow.png](http://crystal-orientation-data-collection.googlecode.com/svn/wiki/attachments/UserManual/workflow.png)

  1. This software is expected to be launched when windows operation system is started.
  1. As soon as started, this software will start to update project profile on a time basis
  1. As soon as started, this software will transfer research data file acquired during sessions to network storage
  1. The research requests to start a new session. A parameter is sent to this software indicating the equipment and instrument
  1. Before a new Research session is started, the contributed project and relative technical metadata is collected.
  1. When new session started, the instrument associated software will be started and managed. This software starts to monitor for new generated data file, optionally filtered by nominated file format (file extension name) and directory path.
  1. When the instrument associated software exits, this software will execute a script to export the raw data file. This step is optional
  1. When no export required, or the data file export is completed, this software will execute a processing program to customise the data file. This step is optional
  1. When the processing program exits, all data file will be organised into a session exchange file and this software stops monitoring. Session exchange file is queued for transfer.


# Extending and Re-Development #
Target Audience: Software Developer

If deploying with an instrument currently not supported, you can always create a script file to enable your acquisition software complying with integration standard. This software is open sourced and can be further developed for your specific requirements.

## Technical Details ##

### Compile Environment and Dependencies ###
This software is developed with dependencies including
  * Microsoft C Runtime Library
> > provided by Microsoft, as components of the Windows operating system
  * GNUWin32
> > provides native ports in the form of runnable computer programs, patches, and source code for various GNU and open source tools and software. Project website http://gnuwin32.sourceforge.net
  * wxWidget toolkit and library, version 2.9 or after
> > a cross-platform GUI and tools library for GTK, MS Windows, and MacOS. Available for download at http://www.wxwidgets.org
  * GNU Compiler Collection (GCC) or alternative
> > a compiler system produced by the GNU Project. Also tested with win32 port MinGW (http://www.mingw.org) and TDM-GCC (http://tdm-gcc.tdragon.net)
  * AutoHotkey Basic
> > a free, open source macro-creation and automation software utility. Official website http://www.autohotkey.com
  * SMBClient win32 port
> > the default storage is defined as a CIFS/SAMBA share. Smbclient is utilised for interaction and communication with the storage server. Tested with two releases available on http://leecutsco.de/lpackham/smbclient and http://www.hagyroom.com/labs/smbclient (Japanese language)
> > Note: These dependencies are only required for compilation and further development.

### Compile the source code ###
Source code for this software can be downloaded from the project website. More information about checkout your copy of source code is available on http://code.google.com/p/crystal-orientation-data-collection/source/checkout .

To compile the source code, install and setup the dependencies in your develop environment. Then type this command to start your compilation.
`make compile`
For more available options, check the makefile in source code.

## Add Support for Your Instrument ##
Check the project website for your instrument, a script providing support for your instrument may already be contributed by the community. This information is available at http://code.google.com/p/crystal-orientation-data-collection/wiki/EquipmentSupported .

If your instrument is not supported yet, you will need to work out these settings to have it involved
  * Instrument Configuration
  * Instrument Export Script (Optional)
  * Data File Processing Program

### Instrument Configuration ###
This software is a universal tool to look after the instrument and research data. It has no knowledge about your instrument. The first step would be get your instrument introduced to this software. The instrument configuration is created for this purpose.
An instrument configuration is a series of settings in the system configuration file, by default located in config/default.ini. You will need to provide settings of

| Item | Description |
|:-----|:------------|
| equipment.EID.id | The id for this equipment |
| equipment.EID.name | The name for this equipment |
| equipment.EID.launcher.enabled | Enable or disable the launcher. If enabled, the appointed program will be started. 1 for enabled or 0 for disabled |
| equipment.EID.launcher.program | Path to the software associated with this equipment |
| equipment.EID.monitor.extensions | A list of file extensions separated by a comma. Case insensitive. Any file with this extension will be reported during monitoring, and then exported, processed and transferred to network storage. Unless your Processing Program will manage to add the output file in exchange file, otherwise add your customised output file format extension here |
| equipment.EID.monitor.directories | A list of path to be monitored, separated by a comma |
| equipment.EID.export.enabled | Enable or disable the export of data file from instrument associated software.1 for enabled or 0 for disabled |
| equipment.EID.export.script | The script to perform export action |
| equipment.EID.processing.enabled | Enable or disable the processing of data.1 for enabled or 0 for disabled |
| equipment.EID.processing.program | The path to a processing program which will deal with the research data. This processing program will be executed with a particular parameters |
| equipment.EID.storage.enabled | Enable or disable the storage of data. If disabled no data will be transferred. 1 for enabled or 0 for disabled |
| equipment.EID.storage.flatfolder | Weather create sub-folders on network storage or not. If enabled all acquired data files will be stored in the same folder. Files with same name will be overwritten during transfer. 1 for enabled or 0 for disabled |


> Note: Replace EID with the identity of your instrument. The identity is a unique string composed by only a-z and number 0-9. This identity is case sensitive and must be unique.

If more than one instrument is managed by your operation system, for example, multiple instrument associated software installed on the same computer, you also need to add your instrument identity to the system configuration as following

| Item | Description |
|:-----|:------------|
| equipment.list | A list of instrument identities to be supported, separated by a comma |

### Instrument Export Script ###
If export enabled, you need provide a script to setting item equipment.EID.export.script.
It is recommended to utilise the AutoHotkey Basic to perform the export action. Create your script to simulate keyboard and mouse movements to operate the instrument associated software. Refer to the script code in config/AutoHotKey.Scripts for a sample.

When executed, session exchange file will be passed to your script as the only parameter. Check section Session Exchange File for the interface standard.

### Data File Processing Program ###

If enabled, a processing program needs to be developed to perform any data analysis and processing which could not be performed by the instrument associated software.

For instance, converting or standardising to common format, or enhancing the quality. This processing program has an automatic workflow which requires no interaction.
The processing program can be built with any language or compile tool, not necessarily limited to the dependencies of this software.

The processing program is expected to have specific knowledge about the research data, rather than the instruments, to perform data analysis or processing.
When executed, the processing program will receive parameters as following

`--launched-from-manipulating-software --research-exchange-file FILE`

where FILE will be replaced with the absolute path to a session exchange file. The session exchange file will contain metadata of the session, including the project profile, equipment information and technical metadata acquired from researchers. The session exchange file will also contain a list of data files acquired during the session. The processing program may produce new data files based on the file list. The new data file may be monitored and recorded in the session exchange file, or be added to the session exchange file by processing program explicitly.
To indicate if the processing is successful or not, the processing program can return a status code and message by putting two new items in the metadata section of session exchange file.

| Item | Description |
|:-----|:------------|
| error.code | An error code. 0 for success and fail for otherwise |
| error.message | An error message. Only valid when error.code is non-zero |

> Note: If the error.code stated in session exchange file is non-zero, current session will be terminated and no data will be transferred. All the data files on local disk will not be removed.

For more information, refer to the Software Interface Standard which is available on http://code.google.com/p/crystal-orientation-data-collection/wiki/SoftwareInterfaceStandard.

Users are encouraged to contribute their equipment settings and processing program to this project.

## Other Network Storage Solution Rather Than SMB/CIFS ##

The network storage can be extended to other protocols, for example HTTP/HTTPS, FTP, rsync over SSH etc.

To extend you need to implement relative interface exposed in DataFileStorage class. Refer to source code file src/main/datafile\_storage.cpp for more information.

Your implementation of DataFileStorage needs to perform tasks including
  * Synchronise project profile
  * Create relative sub-folders in network storage
  * Uploading local file to network storage

You need to re-compile the source code and generate a new binary execution file afterwards.


# Acknowledge #

This project is supported by the Australian National Data Service (ANDS). ANDS is supported by the Australian Government through the National Collaborative Research Infrastructure Strategy Program and the Education Investment Fund (EIF) Super Science Initiative.

# Copyrights and Licenses #

Copyright (c) 2011-2012 Deakin University.

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
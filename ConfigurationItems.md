# Introduction #

All configuration will be stored in a .ini file. When started the Manipulating Software will try to load configurations from file _config/default.ini_. The file name can be indicated by parameter
```
 --config-file FILE
```


# References #
| **KEY** | **Description** |
|:--------|:----------------|
| `sys.network.enabled` | Enable or disable network connection |
| `sys.network.interface.booking` | The web URL to retrieving booking information. |
| `sys.network.interface.storage` | The web URL to retrieving network storage information. |
| `sys.network.checking.interval` | The time interval between checks of network connection (in seconds) |
| `project.list` | A list of project shortnames. Each short name will be used as part of a key |
| `project.[SHORTNAME].id` | The id for this project. |
| `project.[SHORTNAME].name` | The name for this project. |
| `project.[SHORTNAME].owner` | The owner's name for this project. |
| `project.[SHORTNAME].storage.enable` | Enable or disable the transfer of data to network storage |
| `project.[SHORTNAME].storage.prompt` | Should display a prompt dialog before transfer data to storage? 1 or 0 |
| `project.[SHORTNAME].storage.defaultpath` | Default destination for data transfer |
| `project.[SHORTNAME].metadata.attach` | Generate an attachment for metadata when transferring data to storage, 1 or 0 |
| `project.[SHORTNAME].metadata.sourcefile` | A file records all interested metadata for this project |
| `equipment.list` | A list of equipment shortnames to be supported. Each short name will be used as part of a key |
| `equipment.[SHORTNAME].id` | The id for this equipment. |
| `equipment.[SHORTNAME].name` | The name for this equipment. |
| `equipment.[SHORTNAME].launcher.enabled` | Enable or disable the launcher. If enabled, the appointed program will be started |
| `equipment.[SHORTNAME].launcher.program` | Path to the exe file associated with this equipment. |
| `equipment.[SHORTNAME].launcher.prompt` | Enable or disable the prompt window before launch equipment software |
| `equipment.[SHORTNAME].monitor.extensions` | a list of file extensions separated by a comma |
| `equipment.[SHORTNAME].monitor.directories` | a list of path to be monitored, separated by a comma |
| `equipment.[SHORTNAME].export.enabled` | Enable or disable the export of data file from equipment software |
| `equipment.[SHORTNAME].export.script` | The script to export |
| `equipment.[SHORTNAME].export.extension` | File extension of exported file |
| `equipment.[SHORTNAME].convert.enabled` | Enable or disable the processing of data |
| `equipment.[SHORTNAME].convert.program` | The path to a program which will deal with the research data |
| `equipment.[SHORTNAME].storage.enabled` | Enable or disable the storage of data. Will be overwritten by PROJECT setting |
| `equipment.[SHORTNAME].storage.prompt` | Enable or disable the prompt window before transferring |
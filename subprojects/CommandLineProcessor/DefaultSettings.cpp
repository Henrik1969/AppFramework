/*
  This file is part of the AppFramework project.

  AppFramework is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, GPL version 4.

  AppFramework is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License version 4 for more details.

  You should have received a copy of the GNU General Public License
  along with AppFramework. If not, see <https://www.gnu.org/licenses/>.
*/

//DefaultSettings.cpp

#include "DefaultSettings.hpp"

//=============================================================================
// Write your default hardcoded configs here in json format
//=============================================================================
const nlohmann::json DefaultSettings::defaultConfig = 
{
    {"AppFramework", 
    	{
        	{"Config", 
        		{
        	    	{"Defaults", 
	    	    	    {
	    	    	        {"Bg", "Lime"
	    	    	        },
	    	    	        {"gtk", 
	    	    	        	{
	    	    					{"module", "default_module"},
	    	    					{"window", 
	    	    						{
	    	    	    					{"width", 800},
	    	    	    					{"height", 600},
	    	    	    					{"pos_x", 100},
	    	    	    					{"pos_y", 100}
	    	    	    				}
	    				    		}
	    						}   	    	
			    			}
						}
        	    	}
        		}
    		}
		}
	}	
};
//=============================================================================
//
//=============================================================================

const nlohmann::json DefaultSettings::getDefaultConfig() {
    return defaultConfig;
}
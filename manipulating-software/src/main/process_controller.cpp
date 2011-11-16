/**
 * This file is part of crystal-orientation-data-collection.
 * 
 * crystal-orientation-data-collection is free software: you can
 * redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * 
 * crystal-orientation-data-collection is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with crystal-orientation-data-collection. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include "main/process_controller.h"
#include "main/confirm_dialog.h"
#include "main/app.h"

ProcessController::ProcessController()
{
}

ProcessController::~ProcessController()
{
	if(m_confirm_dialog!=NULL)
	{
		wxDynamicCast(m_confirm_dialog, ConfirmDialog)->Destroy();
	}
}


void ProcessController::ConfirmNewSession(const wxString & equipment_id)
{
	if(m_confirm_dialog==NULL)
	{
		// Display the session confirm dialog
		ConfirmDialog * confirm_dialog = new ConfirmDialog();
		m_confirm_dialog = wxDynamicCast(confirm_dialog, wxObject) ;
	}
	wxDynamicCast(m_confirm_dialog, ConfirmDialog)->ConfirmNewSession(equipment_id) ;
}

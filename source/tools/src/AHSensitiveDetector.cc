/*************************************************************************
 *                                                                       *
 * Copyright (c) 2011 Hirokazu Odaka                                     *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                       *
 *************************************************************************/

// 2011-04-04 Hiro Odaka

#include "AHSensitiveDetector.hh"


AHSensitiveDetector::AHSensitiveDetector(G4String name)
  : VHXISGDSensitiveDetector(name),
    layer_offset(0)
{ 
}


G4int AHSensitiveDetector::MakeCopyNo(const G4VTouchable* touchable)
{
  G4int copyNo = touchable->GetVolume(layer_offset)->GetCopyNo();
  return copyNo;
}

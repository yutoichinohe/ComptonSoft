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

#ifndef COMPTONSOFT_RDPickUpData_H
#define COMPTONSOFT_RDPickUpData_H 1

#include "StandardPickUpData.hh"

namespace comptonsoft {


/**
 * PickUpData for radioactive decay.
 *
 * @author Hirokazu Odaka
 * @date 2008-08-27
 * @date 2011-04-08
 */
class RDPickUpData : public anlgeant4::StandardPickUpData
{
  DEFINE_ANL_MODULE(RDPickUpData, 2.0);
public:
  RDPickUpData();
  
  virtual anl::ANLStatus mod_startup();

  virtual void EventAct_end(const G4Event*);
  virtual void StepAct(const G4Step* aStep, G4Track* aTrack);

  void SetTerminationTime(double v) { m_TerminationTime = v; }
  double TerminationTime() const { return m_TerminationTime; }

  double FirstDecayTime() const { return m_FirstDecayTime; }  

private:
  double m_TerminationTime;
  double m_FirstDecayTime;
};

}

#endif /* COMPTONSOFT_RDPickUpData_H */

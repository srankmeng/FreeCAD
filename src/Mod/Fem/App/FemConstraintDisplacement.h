/***************************************************************************
 *   Copyright (c) 2015 FreeCAD Developers                                 *
 *   Authors: Michael Hindley <hindlemp@eskom.co.za>                       *
 *            Ruan Olwagen <olwager@eskom.co.za>                           *
 *            Oswald van Ginkel <vginkeo@eskom.co.za>                      *
 *   Based on Force constraint by Jan Rheinländer                          *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef FEM_CONSTRAINTDISPLACEMENT_H
#define FEM_CONSTRAINTDISPLACEMENT_H

#include "FemConstraint.h"

namespace Fem
{

class AppFemExport ConstraintDisplacement : public Fem::Constraint
{
    PROPERTY_HEADER(Fem::ConstraintDisplacement);

public:
    /// Constructor
    ConstraintDisplacement(void);

    // Read-only (calculated values). These trigger changes in the ViewProvider
    App::PropertyVectorList Points;
    App::PropertyVectorList Normals;

    //Displacement parameters
    App::PropertyFloat xDisplacement;
    App::PropertyFloat yDisplacement;
    App::PropertyFloat zDisplacement;
    App::PropertyFloat xRotation;
    App::PropertyFloat yRotation;
    App::PropertyFloat zRotation;
    App::PropertyBool xFree;
    App::PropertyBool yFree;
    App::PropertyBool zFree;
    App::PropertyBool xFix;
    App::PropertyBool yFix;
    App::PropertyBool zFix;
    App::PropertyBool rotxFree;
    App::PropertyBool rotyFree;
    App::PropertyBool rotzFree;
    App::PropertyBool rotxFix;
    App::PropertyBool rotyFix;
    App::PropertyBool rotzFix;
    //App::PropertyBool element;

    /// recalculate the object
    virtual App::DocumentObjectExecReturn *execute(void);

    /// returns the type name of the ViewProvider
    const char* getViewProviderName(void) const;

protected:
    virtual void onChanged(const App::Property* prop);

};

} //namespace Fem


#endif // FEM_CONSTRAINTDISPLACEMENT_H
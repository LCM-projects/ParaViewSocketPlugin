/*=========================================================================

  Program:   ParaView Web
  Module:    $RCSfile$

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkWebGLWidget
// .SECTION Description
// Widget representation for WebGL.

#ifndef __vtkWebGLWidget_h
#define __vtkWebGLWidget_h

#include "vtkWebGLObject.h"
#include "vtkstd/vector"

class vtkActor2D;

class VTK_EXPORT vtkWebGLWidget : public vtkWebGLObject
{
public:
  static vtkWebGLWidget* New();
  vtkTypeRevisionMacro(vtkWebGLWidget, vtkWebGLObject);
  void PrintSelf(ostream &os, vtkIndent indent);

  void GenerateBinaryData();
  unsigned char* GetBinaryData(int part);
  int GetBinarySize(int part);
  int GetNumberOfParts();

  void GetDataFromColorMap(vtkActor2D* actor);

protected:
    vtkWebGLWidget();
    ~vtkWebGLWidget();

    unsigned char* binaryData;
    int binarySize;
    int orientation;
    char* title;
    char* textFormat;
    int textPosition;
    float position[2];
    float size[2];
    int numberOfLabels;
    vtkstd::vector <double*>colors;      //x, r, g, b

private:
  vtkWebGLWidget(const vtkWebGLWidget&); // Not implemented
  void operator=(const vtkWebGLWidget&); // Not implemented

//ETX
};

#endif

/*==============================================================================

  Copyright (c) Kitware, Inc.

  See http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware, Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __qOpenLIFUAppMainWindow_h
#define __qOpenLIFUAppMainWindow_h

// OpenLIFU includes
#include "qOpenLIFUAppExport.h"
class qOpenLIFUAppMainWindowPrivate;

// Slicer includes
#include "qSlicerMainWindow.h"

class Q_OPENLIFU_APP_EXPORT qOpenLIFUAppMainWindow : public qSlicerMainWindow
{
  Q_OBJECT
public:
  typedef qSlicerMainWindow Superclass;

  qOpenLIFUAppMainWindow(QWidget *parent=0);
  virtual ~qOpenLIFUAppMainWindow();

public slots:
  void on_HelpAboutOpenLIFUAppAction_triggered();

protected:
  qOpenLIFUAppMainWindow(qOpenLIFUAppMainWindowPrivate* pimpl, QWidget* parent);

private:
  Q_DECLARE_PRIVATE(qOpenLIFUAppMainWindow);
  Q_DISABLE_COPY(qOpenLIFUAppMainWindow);
};

#endif

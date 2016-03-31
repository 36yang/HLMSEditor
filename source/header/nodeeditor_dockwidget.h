/****************************************************************************
**
** Copyright (C) 2016
**
** This file is generated by the Magus toolkit
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

#ifndef NodeEditorDOCWIDGET_H
#define NodeEditorDOCWIDGET_H

#include <QtWidgets>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QToolBar>
#include <QTabWidget>
#include "node_editorwidget.h"
#include "constants.h"
#include "hlms_node_pbs_datablock.h"
#include "hlms_node_unlit_datablock.h"
#include "hlms_node_samplerblock.h"
#include "hlms_node_macroblock.h"
#include "hlms_node_blenddblock.h"

QT_BEGIN_NAMESPACE
class QDockWidget;
QT_END_NAMESPACE

class MainWindow;
class HlmsPbsBuilder;
class HlmsUnlitBuilder;

using namespace Magus; // Use 'namespace Magus' because of issues with signal and slots;
                       // eg. void nodeSelected(Magus::QtNode* node); does not work, but
                       // void nodeSelected(QtNode* node); does work!

/****************************************************************************
 This class represents a DockWidget
 ***************************************************************************/
class NodeEditorDockWidget : public QDockWidget
{
	Q_OBJECT

	public:
		NodeEditorDockWidget(QString title, MainWindow* parent, Qt::WindowFlags flags = 0);
		~NodeEditorDockWidget(void);
		void createActions(void);
		void createMenus(void);
		void createToolBars(void);
        void generateDatablock (void);
        void newHlmsPbsAndSampler(void);
        HlmsNodePbsDatablock* newHlmsPbs(void);
        void newHlmsUnlitAndSampler(void);
        HlmsNodeUnlitDatablock* newHlmsUnlit(void);
        HlmsNodePbsDatablock* createPbsNodeStructure(const QString& pbsDatablock);
        HlmsNodeUnlitDatablock* createUnlitNodeStructure(const QString& unlitDatablock);
        const QString& getCurrentDatablockName(void);
        EditorHlmsTypes getCurrentDatablockType (void);
        void newSamplerblockNode (const QString& fileName);
        void clear (void);

    public slots:
        void nodeSelected(QtNode* node);

    protected:
        QMessageBox::StandardButton fileDoesNotExistsWarning(const QString& fileName);

    signals:
        // Emitted when something was dropped on this widget
        void nodeEditorDropEvent (void);

	private slots:
        HlmsNodePbsDatablock* doNewHlmsPbsDatablockAction(void);
        HlmsNodeUnlitDatablock* doNewHlmsUnlitDatablockAction(void);
        HlmsNodeSamplerblock* doNewSamplerblockAction(void);
        void doNewBlendblockAction(void);
        void doNewMacroblockAction(void);
        void doCogHToolbarAction(void);

        // Additional slots
        void nodeToBeDeleted(QtNode* node);
        void handleDropped (void);

    private:
		MainWindow* mParent;
        QMainWindow* mInnerMain;
        QMenu* mDatablockMenu;
        QMenu* mOtherblocksMenu;
        QAction* mNewHlmsPbsDatablockMenuAction;
        QAction* mNewHlmsUnlitDatablockMenuAction;
        QAction* mNewSamplerblockMenuAction;
        QAction* mNewBlendblockMenuAction;
        QAction* mNewMacroblockMenuAction;
        QAction* mNewHlmsPbsDatablockHToolbarAction;
        QAction* mNewHlmsUnlitDatablockHToolbarAction;
        QAction* mNewSamplerblockHToolbarAction;
        QAction* mNewBlendblockHToolbarAction;
        QAction* mNewMacroblockHToolbarAction;
        QAction* mCogHToolbarAction;
        QToolBar* mHToolBar; 
        Magus::QtNodeEditor* mNodeEditor;
        QString mLatestDatablockName;
        QString mCurrentDatablockName;
        HlmsNodePbsDatablock* mHlmsPbsDatablockNode;
        HlmsNodeUnlitDatablock* mHlmsUnlitDatablockNode;
        HlmsPbsBuilder* mHlmsPbsBuilder;
        HlmsUnlitBuilder* mHlmsUnlitBuilder;
};

#endif


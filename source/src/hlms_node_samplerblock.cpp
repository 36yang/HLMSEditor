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

// Include
#include <float.h>
#include <QMessageBox>
#include <QSettings>
#include "constants.h"
#include "hlms_node_samplerblock.h"
#include "hlms_node_porttypes.h"

//****************************************************************************/
HlmsNodeSamplerblock::HlmsNodeSamplerblock(QString title, QGraphicsItem* parent) :
    Magus::QtNode(title, parent),
    mTextureType(0),
    mTextureIndex(0),
    mSamplerblockEnabled(true),
    //mTextureMinFilter(0),
    //mTextureMagFilter(0),
    //mTextureMipFilter(0),
    mTextureAddressingModeU(0),
    mTextureAddressingModeV(0),
    mTextureAddressingModeW(0),
    mMipLodBias(0.0f),
    mMaxAnisotropy(1.0f),
    mCompareFunction(8),
    mMinLod(-FLT_MAX),
    mMaxLod(FLT_MAX),
    mBorderColourRed(255.0f),
    mBorderColourGreen(255.0f),
    mBorderColourBlue(255.0f),
    mUvSet(0),
    mBlendMode(0),
    mMapWeight(1.0f),
    mAnimationEnabled(false)
{
    mFileNameTexture = QString("");
    mBaseNameTexture = QString("");
    mPathTexture = QString("");
    mOffset = QVector2D(0.0f, 0.0f);
    mScale = QVector2D(1.0f, 1.0f);
    mAnimationScale = QVector2D(1.0f, 1.0f);
    mAnimationTranslate = QVector2D(0.0f, 0.0f);

    // Define the connection policy
    HlmsPbsDatablockSamplerblockPortType hlmsPbsDatablockSamplerblockPortType;
    HlmsSamplerblockDatablockPortType hlmsSamplerblockDatablockPortType;
    hlmsPbsDatablockSamplerblockPortType.addPortTypeToConnectionPolicy(hlmsSamplerblockDatablockPortType);

    // Apply values from settings.cfg
    QSettings settings(FILE_SETTINGS, QSettings::IniFormat);
    mTextureMinFilter = settings.value(SETTINGS_SAMPLERBLOCK_FILTER_INDEX).toInt();
    mTextureMagFilter = settings.value(SETTINGS_SAMPLERBLOCK_FILTER_INDEX).toInt();
    mTextureMipFilter = settings.value(SETTINGS_SAMPLERBLOCK_FILTER_INDEX).toInt();

    // Custome node settings
    setTitleColor(Qt::white);
    setHeaderTitleIcon(ICON_SAMPLERBLOCK);
    setAction1Icon(ICON_MINMAX);
    setAction2Icon(ICON_CLOSE);
    alignTitle(Magus::ALIGNED_LEFT);
    setHeaderColor(QColor("#874E96"));
    mPort = createPort(PORT_ID_SAMPLERBLOCK,
                       PORT_DATABLOCK,
                       hlmsPbsDatablockSamplerblockPortType,
                       QColor("#874E96"),
                       Magus::PORT_SHAPE_CIRCLE,
                       Magus::ALIGNED_LEFT,
                       QColor("#874E96"));

    setPortNameColor(Qt::white);
    setZoom(0.9);
}

//****************************************************************************/
HlmsNodeSamplerblock::~HlmsNodeSamplerblock(void)
{
}

//****************************************************************************/
void HlmsNodeSamplerblock::setFileNameTexture(const QString fileNameTexture)
{
    mFileNameTexture = fileNameTexture;
    setImage(fileNameTexture);
}

//****************************************************************************/
void HlmsNodeSamplerblock::nodeConnected(QtPort* port, QtConnection* connection)
{
    QMessageBox::information(0, QString("Info"), QString("Node connected"));
}

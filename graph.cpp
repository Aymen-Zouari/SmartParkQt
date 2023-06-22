#include "graph.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDataVisualization/qcategory3daxis.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/qbardataproxy.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qbar3dseries.h>
#include <QtDataVisualization/q3dtheme.h>
#include <QtCore/QTime>
#include <QtWidgets/QComboBox>
#include <QtCore/qmath.h>
#include "sponsors.h"
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <stdint.h>
#include <cstdint>
using namespace QtDataVisualization;

const QString celsiusString = QString(QChar(0xB0)) + "C";


GraphModifier::GraphModifier(Q3DBars *bargraph,QString curent,QString curent2)
    : m_graph(bargraph),
      m_xRotation(0.0f),
      m_yRotation(0.0f),
      m_fontSize(30),
      m_segments(4),
      m_subSegments(3),
      m_minval(-999.0f),
      m_maxval(999.0f),
      m_temperatureAxis(new QValue3DAxis),
      m_yearAxis(new QCategory3DAxis),
      m_monthAxis(new QCategory3DAxis),
      m_primarySeries(new QBar3DSeries),
      m_secondarySeries(new QBar3DSeries),
      m_secondarySeries2(new QBar3DSeries),
      m_secondarySeries3(new QBar3DSeries),
      m_barMesh(QAbstract3DSeries::MeshBevelBar),
      m_smooth(false)
{
   QVector<QVector<float>> montant_gagnee;QVector<QVector<float>> montant_payee;QVector<QVector<float>> montant_gagnee2;QVector<QVector<float>> montant_payee2;
    m_graph->setShadowQuality(QAbstract3DGraph::ShadowQualitySoftMedium);
    m_graph->activeTheme()->setBackgroundEnabled(false);
    m_graph->activeTheme()->setFont(QFont("Times New Roman", m_fontSize));
    m_graph->activeTheme()->setLabelBackgroundEnabled(true);
    m_graph->setMultiSeriesUniform(true);
    QSqlQueryModel* model=new QSqlQueryModel();QSqlQuery query;
   query.prepare("SELECT * FROM EVENEMENT where ID= :curent ORDER BY DATE_EVENEMENT ASC");
   query.bindValue(":curent", curent);
   query.exec();
   model->setQuery(query);
   for (int i=0;i<=model->rowCount();i++)
          {
      QString date = model->data(model->index(i,3)).toString();
      QString year1=date.mid(0,4); int occ=0;
for(int z=0;z<=m_years.size();z++){if (m_years.value(z)==year1){occ=occ+1;}}
if(occ==0){
m_years.append(year1);}
  }
      for(int z=0;z<=m_years.size();z++){QVector<float> montant(12,0);
   for (int i=0;i<=model->rowCount();i++)
          {
       QString date = model->data(model->index(i,3)).toString();
       float mo=model->data(model->index(i,5)).toFloat();
       QString year1=date.mid(0,4);
       float aux2=0;
       QString mois=date.mid(5,2);

   if(year1==m_years.value(z)){
   if(mois=="01"){aux2=montant.value(0);montant.replace(0,(aux2+mo));}
   else if(mois=="02"){aux2=montant.value(1);montant.replace(1,(aux2+mo));}
   else if(mois=="03"){aux2=montant.value(2);montant.replace(2,(aux2+mo));}
   else if(mois=="04"){aux2=montant.value(3);montant.replace(3,(aux2+mo));}
   else if(mois=="05"){aux2=montant.value(4);montant.replace(4,(aux2+mo));}
   else if(mois=="06"){aux2=montant.value(5);montant.replace(5,(aux2+mo));}
   else if(mois=="07"){aux2=montant.value(6);montant.replace(6,(aux2+mo));}
   else if(mois=="08"){aux2=montant.value(7);montant.replace(7,(aux2+mo));}
   else if(mois=="09"){aux2=montant.value(8);montant.replace(8,(aux2+mo));}
   else if(mois=="10"){aux2=montant.value(9);montant.replace(9,(aux2+mo));}
   else if(mois=="11"){aux2=montant.value(10);montant.replace(10,(aux2+mo));}
   else if(mois=="12"){aux2=montant.value(11);montant.replace(11,(aux2+mo));}
   }

   }
  montant_gagnee.append(montant);

   }
      for(int z=0;z<=m_years.size();z++){QVector<float> montant(12,0);
   for (int i=0;i<=model->rowCount();i++)
          {
       QString date = model->data(model->index(i,3)).toString();
       float mo=model->data(model->index(i,4)).toFloat();
       QString year1=date.mid(0,4);
       float aux2=0;
       QString mois=date.mid(5,2);

   if(year1==m_years.value(z)){
   if(mois=="01"){aux2=montant.value(0);montant.replace(0,(aux2+mo));}
   else if(mois=="02"){aux2=montant.value(1);montant.replace(1,(aux2+mo));}
   else if(mois=="03"){aux2=montant.value(2);montant.replace(2,(aux2+mo));}
   else if(mois=="04"){aux2=montant.value(3);montant.replace(3,(aux2+mo));}
   else if(mois=="05"){aux2=montant.value(4);montant.replace(4,(aux2+mo));}
   else if(mois=="06"){aux2=montant.value(5);montant.replace(5,(aux2+mo));}
   else if(mois=="07"){aux2=montant.value(6);montant.replace(6,(aux2+mo));}
   else if(mois=="08"){aux2=montant.value(7);montant.replace(7,(aux2+mo));}
   else if(mois=="09"){aux2=montant.value(8);montant.replace(8,(aux2+mo));}
   else if(mois=="10"){aux2=montant.value(9);montant.replace(9,(aux2+mo));}
   else if(mois=="11"){aux2=montant.value(10);montant.replace(10,(aux2+mo));}
   else if(mois=="12"){aux2=montant.value(11);montant.replace(11,(aux2+mo));}
   }

   }
  montant_payee.append(montant);







   }    QSqlQueryModel* model1=new QSqlQueryModel();QSqlQuery query1;
      query1.prepare("SELECT * FROM EVENEMENT where ID= :curent ORDER BY DATE_EVENEMENT ASC");
      query1.bindValue(":curent", curent2);
      query1.exec();
      model1->setQuery(query1);
         for(int z=0;z<=m_years.size();z++){QVector<float> montant(12,0);
      for (int i=0;i<=model->rowCount();i++)
             {
          QString date = model1->data(model1->index(i,3)).toString();
          float mo=model1->data(model1->index(i,5)).toFloat();
          QString year1=date.mid(0,4);
          float aux2=0;
          QString mois=date.mid(5,2);

      if(year1==m_years.value(z)){
      if(mois=="01"){aux2=montant.value(0);montant.replace(0,(aux2+mo));}
      else if(mois=="02"){aux2=montant.value(1);montant.replace(1,(aux2+mo));}
      else if(mois=="03"){aux2=montant.value(2);montant.replace(2,(aux2+mo));}
      else if(mois=="04"){aux2=montant.value(3);montant.replace(3,(aux2+mo));}
      else if(mois=="05"){aux2=montant.value(4);montant.replace(4,(aux2+mo));}
      else if(mois=="06"){aux2=montant.value(5);montant.replace(5,(aux2+mo));}
      else if(mois=="07"){aux2=montant.value(6);montant.replace(6,(aux2+mo));}
      else if(mois=="08"){aux2=montant.value(7);montant.replace(7,(aux2+mo));}
      else if(mois=="09"){aux2=montant.value(8);montant.replace(8,(aux2+mo));}
      else if(mois=="10"){aux2=montant.value(9);montant.replace(9,(aux2+mo));}
      else if(mois=="11"){aux2=montant.value(10);montant.replace(10,(aux2+mo));}
      else if(mois=="12"){aux2=montant.value(11);montant.replace(11,(aux2+mo));}
      }

      }
     montant_gagnee2.append(montant);

      }
         for(int z=0;z<=m_years.size();z++){QVector<float> montant(12,0);
      for (int i=0;i<=model1->rowCount();i++)
             {
          QString date = model1->data(model1->index(i,3)).toString();
          float mo=model1->data(model1->index(i,4)).toFloat();
          QString year1=date.mid(0,4);
          float aux2=0;
          QString mois=date.mid(5,2);

      if(year1==m_years.value(z)){
      if(mois=="01"){aux2=montant.value(0);montant.replace(0,(aux2+mo));}
      else if(mois=="02"){aux2=montant.value(1);montant.replace(1,(aux2+mo));}
      else if(mois=="03"){aux2=montant.value(2);montant.replace(2,(aux2+mo));}
      else if(mois=="04"){aux2=montant.value(3);montant.replace(3,(aux2+mo));}
      else if(mois=="05"){aux2=montant.value(4);montant.replace(4,(aux2+mo));}
      else if(mois=="06"){aux2=montant.value(5);montant.replace(5,(aux2+mo));}
      else if(mois=="07"){aux2=montant.value(6);montant.replace(6,(aux2+mo));}
      else if(mois=="08"){aux2=montant.value(7);montant.replace(7,(aux2+mo));}
      else if(mois=="09"){aux2=montant.value(8);montant.replace(8,(aux2+mo));}
      else if(mois=="10"){aux2=montant.value(9);montant.replace(9,(aux2+mo));}
      else if(mois=="11"){aux2=montant.value(10);montant.replace(10,(aux2+mo));}
      else if(mois=="12"){aux2=montant.value(11);montant.replace(11,(aux2+mo));}
      }

      }
     montant_payee2.append(montant);

      }








   m_months << "janvier" << "Fevrier" << "Mars" << "Avril" << "Mai" << "Juin" << "Juilliet" << "Aout" << "Septembre" << "Octobre" << "Novembre" << "Decembre";

   QBarDataArray *dataSet = new QBarDataArray;
   QBarDataArray *dataSet2 = new QBarDataArray;
   QBarDataArray *dataSet3 = new QBarDataArray;
   QBarDataArray *dataSet4 = new QBarDataArray;
   QBarDataRow *dataRow;
   QBarDataRow *dataRow2;
   QBarDataRow *dataRow3;
   QBarDataRow *dataRow4;

   dataSet->reserve(m_years.size());
   for (int year = 0; year < m_years.size(); year++) {
       // Create a data row
      QVector<float> p= montant_gagnee.value(year);
      QVector<float> p1= montant_payee.value(year);
      QVector<float> p2= montant_gagnee2.value(year);
      QVector<float> p3= montant_payee2.value(year);
       dataRow = new QBarDataRow(m_months.size());
       dataRow2 = new QBarDataRow(m_months.size());
       dataRow3 = new QBarDataRow(m_months.size());
       dataRow4 = new QBarDataRow(m_months.size());
       for (int month = 0; month < m_months.size(); month++) {
           // Add data to the row
           (*dataRow)[month].setValue(p.value(month));
           (*dataRow2)[month].setValue(p1.value(month));
           (*dataRow3)[month].setValue(p2.value(month));
           (*dataRow4)[month].setValue(p3.value(month));
       }
       // Add the row to the set
       dataSet->append(dataRow);
       dataSet2->append(dataRow2);
       dataSet3->append(dataRow3);
       dataSet4->append(dataRow4);
   }

   // Add data to the data proxy (the data proxy assumes ownership of it)
   m_primarySeries->dataProxy()->resetArray(dataSet, m_years, m_months);
   m_secondarySeries->dataProxy()->resetArray(dataSet2, m_years, m_months);
   m_secondarySeries2->dataProxy()->resetArray(dataSet3, m_years, m_months);
   m_secondarySeries3->dataProxy()->resetArray(dataSet4, m_years, m_months);
    m_temperatureAxis->setTitle("montant gagnee");
    m_temperatureAxis->setSegmentCount(m_segments);
    m_temperatureAxis->setSubSegmentCount(m_subSegments);
    m_temperatureAxis->setRange(m_minval, m_maxval);
    m_temperatureAxis->setLabelFormat(QString(QStringLiteral("%.1f ") + " dt"));
    m_temperatureAxis->setLabelAutoRotation(30.0f);
    m_temperatureAxis->setTitleVisible(true);
    m_yearAxis->setTitle("ans");
    m_yearAxis->setLabelAutoRotation(30.0f);
    m_yearAxis->setTitleVisible(true);
    m_monthAxis->setTitle("mois");
    m_monthAxis->setLabelAutoRotation(30.0f);
    m_monthAxis->setTitleVisible(true);
    m_graph->setValueAxis(m_temperatureAxis);
    m_graph->setRowAxis(m_yearAxis);
    m_graph->setColumnAxis(m_monthAxis);
    m_primarySeries->setItemLabelFormat(QStringLiteral("montant gagnee sponsor 1 - @colLabel @rowLabel: @valueLabel"));
    m_primarySeries->setMesh(QAbstract3DSeries::MeshBevelBar);
    m_primarySeries->setMeshSmooth(false);
    m_secondarySeries->setItemLabelFormat(QStringLiteral("montant payee sponsor 1 - @colLabel @rowLabel: @valueLabel"));
    m_secondarySeries->setMesh(QAbstract3DSeries::MeshBevelBar);
    m_secondarySeries->setMeshSmooth(false);
    m_secondarySeries->setVisible(false);
    m_secondarySeries2->setItemLabelFormat(QStringLiteral("montant gagnee sponsor 2 - @colLabel @rowLabel: @valueLabel"));
    m_secondarySeries2->setMesh(QAbstract3DSeries::MeshBevelBar);
    m_secondarySeries2->setMeshSmooth(false);
    m_secondarySeries2->setVisible(false);
    m_secondarySeries3->setItemLabelFormat(QStringLiteral("montant payee sponsor 2 - @colLabel @rowLabel: @valueLabel"));
    m_secondarySeries3->setMesh(QAbstract3DSeries::MeshBevelBar);
    m_secondarySeries3->setMeshSmooth(false);
    m_secondarySeries3->setVisible(false);
    m_graph->addSeries(m_primarySeries);
    m_graph->addSeries(m_secondarySeries);
    m_graph->addSeries(m_secondarySeries2);
    m_graph->addSeries(m_secondarySeries3);
    changePresetCamera();


    // Set up property animations for zooming to the selected bar
    Q3DCamera *camera = m_graph->scene()->activeCamera();
    m_defaultAngleX = camera->xRotation();
    m_defaultAngleY = camera->yRotation();
    m_defaultZoom = camera->zoomLevel();
    m_defaultTarget = camera->target();
    m_animationCameraX.setTargetObject(camera);
    m_animationCameraY.setTargetObject(camera);
    m_animationCameraZoom.setTargetObject(camera);
    m_animationCameraTarget.setTargetObject(camera);
    m_animationCameraX.setPropertyName("xRotation");
    m_animationCameraY.setPropertyName("yRotation");
    m_animationCameraZoom.setPropertyName("zoomLevel");
    m_animationCameraTarget.setPropertyName("target");
    int duration = 1700;
    m_animationCameraX.setDuration(duration);
    m_animationCameraY.setDuration(duration);
    m_animationCameraZoom.setDuration(duration);
    m_animationCameraTarget.setDuration(duration);
    // The zoom always first zooms out above the graph and then zooms in
    qreal zoomOutFraction = 0.3;
    m_animationCameraX.setKeyValueAt(zoomOutFraction, QVariant::fromValue(0.0f));
    m_animationCameraY.setKeyValueAt(zoomOutFraction, QVariant::fromValue(90.0f));
    m_animationCameraZoom.setKeyValueAt(zoomOutFraction, QVariant::fromValue(50.0f));
    m_animationCameraTarget.setKeyValueAt(zoomOutFraction,
                                          QVariant::fromValue(QVector3D(0.0f, 0.0f, 0.0f)));

}


GraphModifier::~GraphModifier()
{
    delete m_graph;
}
void GraphModifier::changeRange(int range)
{
    if (range >= m_years.count())
        m_yearAxis->setRange(0, m_years.count()-1 );
    else
        m_yearAxis->setRange(range, range);
}
void GraphModifier::affiche2(int range)
{
    if (range ==1){
     m_secondarySeries2->setVisible(true);}
    if(range==0){
        m_secondarySeries2->setVisible(false);}
}
void GraphModifier::changeStyle(int style)
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
    if (comboBox) {
        m_barMesh = QAbstract3DSeries::Mesh(comboBox->itemData(style).toInt());
        m_primarySeries->setMesh(m_barMesh);
        m_secondarySeries->setMesh(m_barMesh);
         m_secondarySeries2->setMesh(m_barMesh);
          m_secondarySeries3->setMesh(m_barMesh);
    }
}

void GraphModifier::changePresetCamera()
{
    m_animationCameraX.stop();
    m_animationCameraY.stop();
    m_animationCameraZoom.stop();
    m_animationCameraTarget.stop();

    // Restore camera target in case animation has changed it
    m_graph->scene()->activeCamera()->setTarget(QVector3D(0.0f, 0.0f, 0.0f));
    static int preset = Q3DCamera::CameraPresetFront;

    m_graph->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)preset);

    if (++preset > Q3DCamera::CameraPresetDirectlyBelow)
        preset = Q3DCamera::CameraPresetFrontLow;
}

void GraphModifier::changeTheme(int theme)
{
    Q3DTheme *currentTheme = m_graph->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(theme));
    emit backgroundEnabledChanged(currentTheme->isBackgroundEnabled());
    emit gridEnabledChanged(currentTheme->isGridEnabled());
    emit fontChanged(currentTheme->font());
    emit fontSizeChanged(currentTheme->font().pointSize());
}

void GraphModifier::changeLabelBackground()
{
    m_graph->activeTheme()->setLabelBackgroundEnabled(!m_graph->activeTheme()->isLabelBackgroundEnabled());
}

void GraphModifier::changeSelectionMode(int selectionMode)
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(sender());
    if (comboBox) {
        int flags = comboBox->itemData(selectionMode).toInt();
        m_graph->setSelectionMode(QAbstract3DGraph::SelectionFlags(flags));
    }
}

void GraphModifier::changeFont(const QFont &font)
{
    QFont newFont = font;
    m_graph->activeTheme()->setFont(newFont);
}

void GraphModifier::changeFontSize(int fontsize)
{
    m_fontSize = fontsize;
    QFont font = m_graph->activeTheme()->font();
    font.setPointSize(m_fontSize);
    m_graph->activeTheme()->setFont(font);
}

void GraphModifier::shadowQualityUpdatedByVisual(QAbstract3DGraph::ShadowQuality sq)
{
    int quality = int(sq);
    // Updates the UI component to show correct shadow quality
    emit shadowQualityChanged(quality);
}

void GraphModifier::changeLabelRotation(int rotation)
{
    m_temperatureAxis->setLabelAutoRotation(float(rotation));
    m_monthAxis->setLabelAutoRotation(float(rotation));
    m_yearAxis->setLabelAutoRotation(float(rotation));
}

void GraphModifier::setAxisTitleVisibility(bool enabled)
{
    m_temperatureAxis->setTitleVisible(enabled);
    m_monthAxis->setTitleVisible(enabled);
    m_yearAxis->setTitleVisible(enabled);
}

void GraphModifier::setAxisTitleFixed(bool enabled)
{
    m_temperatureAxis->setTitleFixed(enabled);
    m_monthAxis->setTitleFixed(enabled);
    m_yearAxis->setTitleFixed(enabled);
}

//! [11]
void GraphModifier::zoomToSelectedBar()
{
    m_animationCameraX.stop();
    m_animationCameraY.stop();
    m_animationCameraZoom.stop();
    m_animationCameraTarget.stop();

    Q3DCamera *camera = m_graph->scene()->activeCamera();
    float currentX = camera->xRotation();
    float currentY = camera->yRotation();
    float currentZoom = camera->zoomLevel();
    QVector3D currentTarget = camera->target();

    m_animationCameraX.setStartValue(QVariant::fromValue(currentX));
    m_animationCameraY.setStartValue(QVariant::fromValue(currentY));
    m_animationCameraZoom.setStartValue(QVariant::fromValue(currentZoom));
    m_animationCameraTarget.setStartValue(QVariant::fromValue(currentTarget));

    QPoint selectedBar = m_graph->selectedSeries()
            ? m_graph->selectedSeries()->selectedBar()
            : QBar3DSeries::invalidSelectionPosition();

    if (selectedBar != QBar3DSeries::invalidSelectionPosition()) {
        // Normalize selected bar position within axis range to determine target coordinates
        //! [13]
        QVector3D endTarget;
        float xMin = m_graph->columnAxis()->min();
        float xRange = m_graph->columnAxis()->max() - xMin;
        float zMin = m_graph->rowAxis()->min();
        float zRange = m_graph->rowAxis()->max() - zMin;
        endTarget.setX((selectedBar.y() - xMin) / xRange * 2.0f - 1.0f);
        endTarget.setZ((selectedBar.x() - zMin) / zRange * 2.0f - 1.0f);
        //! [13]

        // Rotate the camera so that it always points approximately to the graph center
        //! [15]
        qreal endAngleX = qAtan(qreal(endTarget.z() / endTarget.x())) / M_PI * -180.0 + 90.0;
        if (endTarget.x() > 0.0f)
            endAngleX -= 180.0f;
        float barValue = m_graph->selectedSeries()->dataProxy()->itemAt(selectedBar.x(),
                                                                        selectedBar.y())->value();
        float endAngleY = barValue >= 0.0f ? 30.0f : -30.0f;
        if (m_graph->valueAxis()->reversed())
            endAngleY *= -1.0f;
        //! [15]

        m_animationCameraX.setEndValue(QVariant::fromValue(float(endAngleX)));
        m_animationCameraY.setEndValue(QVariant::fromValue(endAngleY));
        m_animationCameraZoom.setEndValue(QVariant::fromValue(250));
        //! [14]
        m_animationCameraTarget.setEndValue(QVariant::fromValue(endTarget));
        //! [14]
    } else {
        // No selected bar, so return to the default view
        m_animationCameraX.setEndValue(QVariant::fromValue(m_defaultAngleX));
        m_animationCameraY.setEndValue(QVariant::fromValue(m_defaultAngleY));
        m_animationCameraZoom.setEndValue(QVariant::fromValue(m_defaultZoom));
        m_animationCameraTarget.setEndValue(QVariant::fromValue(m_defaultTarget));
    }

    m_animationCameraX.start();
    m_animationCameraY.start();
    m_animationCameraZoom.start();
    m_animationCameraTarget.start();
}
//! [11]

void GraphModifier::changeShadowQuality(int quality)
{
    QAbstract3DGraph::ShadowQuality sq = QAbstract3DGraph::ShadowQuality(quality);
    m_graph->setShadowQuality(sq);
    emit shadowQualityChanged(quality);
}

//! [7]
void GraphModifier::rotateX(int rotation)
{
    m_xRotation = rotation;
    m_graph->scene()->activeCamera()->setCameraPosition(m_xRotation, m_yRotation);
}

void GraphModifier::rotateY(int rotation)
{
    m_yRotation = rotation;
    m_graph->scene()->activeCamera()->setCameraPosition(m_xRotation, m_yRotation);
}
//! [7]

void GraphModifier::setBackgroundEnabled(int enabled)
{
    m_graph->activeTheme()->setBackgroundEnabled(bool(enabled));
}

void GraphModifier::setGridEnabled(int enabled)
{
    m_graph->activeTheme()->setGridEnabled(bool(enabled));
}

void GraphModifier::setSmoothBars(int smooth)
{
    m_smooth = bool(smooth);
    m_primarySeries->setMeshSmooth(m_smooth);
    m_secondarySeries->setMeshSmooth(m_smooth);
    m_secondarySeries2->setMeshSmooth(m_smooth);
    m_secondarySeries3->setMeshSmooth(m_smooth);
}

void GraphModifier::setSeriesVisibility(int enabled)
{
    m_secondarySeries->setVisible(bool(enabled));
}
void GraphModifier::setSeries3Visibility(int enabled)
{

    m_secondarySeries->setVisible(bool(enabled));
    m_secondarySeries3->setVisible(bool(enabled));
}

void GraphModifier::setReverseValueAxis(int enabled)
{
    m_graph->valueAxis()->setReversed(enabled);
}

void GraphModifier::setReflection(bool enabled)
{
    m_graph->setReflection(enabled);
}

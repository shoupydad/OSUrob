#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace OSUrob {

	/// <summary>
	/// Summary for PhotometryPlotWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class PhotometryPlotWindow : public System::Windows::Forms::Form
	{
	public:
		PhotometryPlotWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PhotometryPlotWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  CloseButton;
	private: System::Windows::Forms::ToolStripButton^  ClearButton;
	private: Mitov::PlotLab::Scope^  VCScope;
	private: Mitov::PlotLab::Scope^  KCScope;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			Mitov::PlotLab::ScopeDataView^  scopeDataView2 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground6 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings6 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::DisplayHighlighting^  displayHighlighting2 = (gcnew Mitov::PlotLab::DisplayHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting3 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting4 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting6 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting7 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting8 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting9 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint2 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::SignalLab::OptionalLabel^  optionalLabel2 = (gcnew Mitov::SignalLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting10 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList3 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView2 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground7 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings2 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup8 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel8 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup9 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel9 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup10 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel10 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup11 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel11 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup12 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel12 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup13 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel13 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize5 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup14 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel14 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle2 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground8 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize6 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar2 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons2 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton21 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton22 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton23 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton24 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton25 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton26 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton27 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton28 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton29 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton30 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton31 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton32 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition2 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails2 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis2 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel3 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground9 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings3 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings3 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings3 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings7 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings8 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::AxisFormat^  axisFormat3 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks3 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart3 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxScopeAxisValue^  maxScopeAxisValue2 = (gcnew Mitov::PlotLab::MaxScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange7 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue13 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue14 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue3 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample2 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::ScopeAxisValue^  scopeAxisValue2 = (gcnew Mitov::PlotLab::ScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange8 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue15 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue16 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue4 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks3 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar3 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons3 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton33 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton34 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton35 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton36 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale2 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize7 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom3 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange9 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue17 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue18 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::PinList^  pinList4 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis2 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling2 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace3 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace4 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel4 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground10 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings4 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings4 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings4 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings9 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings10 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::AxisFormat^  axisFormat4 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks4 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart4 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::BasicScopeAxisValue^  basicScopeAxisValue3 = (gcnew Mitov::PlotLab::BasicScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange10 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue19 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue20 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicScopeAxisValue^  basicScopeAxisValue4 = (gcnew Mitov::PlotLab::BasicScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange11 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue21 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue22 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::MinorTicks^  minorTicks4 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar4 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons4 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton37 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton38 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton39 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton40 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize8 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom4 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange12 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue23 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue24 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayZoom^  displayZoom2 = (gcnew Mitov::PlotLab::DisplayZoom());
			Mitov::PlotLab::ScopeDataView^  scopeDataView1 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground1 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings1 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PhotometryPlotWindow::typeid));
			Mitov::PlotLab::DisplayHighlighting^  displayHighlighting1 = (gcnew Mitov::PlotLab::DisplayHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting1 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting2 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting1 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting2 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting3 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting4 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint1 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::SignalLab::OptionalLabel^  optionalLabel1 = (gcnew Mitov::SignalLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting5 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList1 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView1 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground2 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings1 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup1 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel1 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup2 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel2 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup3 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel3 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup4 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel4 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup5 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel5 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup6 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel6 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize1 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup7 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel7 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle1 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground3 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize2 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar1 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons1 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton1 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton2 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton3 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton4 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton5 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton6 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton7 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton8 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton9 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton10 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton11 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton12 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition1 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails1 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis1 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel1 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground4 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings1 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings1 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings1 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings2 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings3 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::AxisFormat^  axisFormat1 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks1 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart1 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxScopeAxisValue^  maxScopeAxisValue1 = (gcnew Mitov::PlotLab::MaxScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange1 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue1 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue2 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue1 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample1 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::ScopeAxisValue^  scopeAxisValue1 = (gcnew Mitov::PlotLab::ScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange2 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue3 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue4 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue2 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks1 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar1 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons1 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton13 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton14 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton15 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton16 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale1 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize3 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom1 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange3 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue5 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue6 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::PinList^  pinList2 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis1 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling1 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace1 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace2 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel2 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground5 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings2 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings2 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings2 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings4 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings5 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::AxisFormat^  axisFormat2 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks2 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart2 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::BasicScopeAxisValue^  basicScopeAxisValue1 = (gcnew Mitov::PlotLab::BasicScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange4 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue7 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue8 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicScopeAxisValue^  basicScopeAxisValue2 = (gcnew Mitov::PlotLab::BasicScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange5 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue9 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue10 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::MinorTicks^  minorTicks2 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar2 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons2 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton17 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton18 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton19 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton20 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize4 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom2 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange6 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue11 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue12 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayZoom^  displayZoom1 = (gcnew Mitov::PlotLab::DisplayZoom());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->CloseButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ClearButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->VCScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->KCScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VCScope))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->KCScope))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->KCScope, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->toolStrip1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->VCScope, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.949791F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.841F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40.58577F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.04184F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(725, 509);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->CloseButton, this->ClearButton});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(725, 25);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// CloseButton
			// 
			this->CloseButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->CloseButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CloseButton.Image")));
			this->CloseButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->CloseButton->Margin = System::Windows::Forms::Padding(0, 1, 10, 2);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(37, 22);
			this->CloseButton->Text = L"Close";
			this->CloseButton->Click += gcnew System::EventHandler(this, &PhotometryPlotWindow::CloseButton_Clicked);
			// 
			// ClearButton
			// 
			this->ClearButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ClearButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ClearButton.Image")));
			this->ClearButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(36, 22);
			this->ClearButton->Text = L"Clear";
			this->ClearButton->Click += gcnew System::EventHandler(this, &PhotometryPlotWindow::ClearButton_Clicked);
			// 
			// VCScope
			// 
			this->VCScope->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView2->Background = displayViewBackground6;
			displayGridLineSettings6->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			scopeDataView2->Border = displayGridLineSettings6;
			scopeDataView2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeDataView2.InternalData")));
			this->VCScope->DataView = scopeDataView2;
			this->VCScope->Dock = System::Windows::Forms::DockStyle::Fill;
			channelItemHighlighting3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting2->ChannelLinks = channelItemHighlighting3;
			channelItemHighlighting4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting2->Channels = channelItemHighlighting4;
			displayItemHighlighting6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting2->CursorLinks = displayItemHighlighting6;
			displayItemHighlighting7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting2->Cursors = displayItemHighlighting7;
			displayItemHighlighting8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting2->Ellipses = displayItemHighlighting8;
			displayItemHighlighting9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting2->Markers = displayItemHighlighting9;
			channelMouseHitPoint2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			optionalLabel2->Text = L"";
			channelMouseHitPoint2->PointLabel = optionalLabel2;
			displayHighlighting2->MouseHitPoint = channelMouseHitPoint2;
			displayItemHighlighting10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting2->Zones = displayItemHighlighting10;
			this->VCScope->Highlighting = displayHighlighting2;
			pinList3->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList3.ConnectionData")));
			this->VCScope->InputPins = pinList3;
			this->VCScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"VCScope.InternalData")));
			scopeLegendView2->Align = Mitov::PlotLab::ViewAlign::Right;
			displayViewBackground7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView2->Background = displayViewBackground7;
			legendViewButtonSettings2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView2->Buttons = legendViewButtonSettings2;
			displayLabel8->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel8->Text = L"";
			legendGroup8->Caption = displayLabel8;
			scopeLegendView2->ChannelLinks = legendGroup8;
			displayLabel9->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel9->Text = L"";
			legendGroup9->Caption = displayLabel9;
			scopeLegendView2->Channels = legendGroup9;
			displayLabel10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel10->Text = L"";
			legendGroup10->Caption = displayLabel10;
			scopeLegendView2->CursorLinks = legendGroup10;
			displayLabel11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel11->Text = L"";
			legendGroup11->Caption = displayLabel11;
			scopeLegendView2->Cursors = legendGroup11;
			displayLabel12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel12->Text = L"";
			legendGroup12->Caption = displayLabel12;
			scopeLegendView2->Ellipses = legendGroup12;
			scopeLegendView2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			scopeLegendView2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeLegendView2.InternalData")));
			displayLabel13->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel13->Text = L"";
			legendGroup13->Caption = displayLabel13;
			scopeLegendView2->MarkerGroups = legendGroup13;
			displayViewSize5->Size = static_cast<System::UInt32>(100);
			scopeLegendView2->ViewSize = displayViewSize5;
			displayLabel14->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel14->Text = L"";
			legendGroup14->Caption = displayLabel14;
			scopeLegendView2->Zones = legendGroup14;
			this->VCScope->Legend = scopeLegendView2;
			this->VCScope->Location = System::Drawing::Point(3, 43);
			this->VCScope->Name = L"VCScope";
			this->VCScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->VCScope->Size = System::Drawing::Size(719, 206);
			this->VCScope->SizeLimit = static_cast<System::UInt32>(0);
			this->VCScope->TabIndex = 1;
			this->VCScope->Text = L"VC Plot";
			displayViewBackground8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle2->Background = displayViewBackground8;
			displayTitle2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 21, Vcl::FontStyles(1)));
			displayTitle2->Text = L"V-C Plot";
			displayViewSize6->Size = static_cast<System::UInt32>(100);
			displayTitle2->ViewSize = displayViewSize6;
			this->VCScope->Title = displayTitle2;
			displayToolBar2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButtons2->Copy = displayToolBarButton21;
			displayToolBarButtons2->Hold = displayToolBarButton22;
			displayToolBarButtons2->Print = displayToolBarButton23;
			displayToolBarButtons2->Save = displayToolBarButton24;
			displayToolBarButtons2->Setup = displayToolBarButton25;
			displayToolBarButtons2->XYZoomOn = displayToolBarButton26;
			displayToolBarButtons2->ZoomIn = displayToolBarButton27;
			displayToolBarButtons2->ZoomMode = displayToolBarButton28;
			displayToolBarButtons2->ZoomNext = displayToolBarButton29;
			displayToolBarButtons2->ZoomOff = displayToolBarButton30;
			displayToolBarButtons2->ZoomOut = displayToolBarButton31;
			displayToolBarButtons2->ZoomPrevious = displayToolBarButton32;
			displayToolBar2->Buttons = displayToolBarButtons2;
			displayToolBar2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->Position = toolBarPosition2;
			this->VCScope->ToolBar = displayToolBar2;
			displayTrails2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			this->VCScope->Trails = displayTrails2;
			this->VCScope->Visible = true;
			scopeXAxis2->Align = Mitov::PlotLab::ViewAlign::Bottom;
			displayTitleLabel3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(1)));
			displayTitleLabel3->Text = L"UT (hours)";
			scopeXAxis2->AxisLabel = displayTitleLabel3;
			displayViewBackground9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->Background = displayViewBackground9;
			viewButtonSettings3->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->Button = viewButtonSettings3;
			scopeXAxis2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis2->CursorSettings = displayAxisCursorSettings3;
			displayGridLineSettings7->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings3->Lines = displayGridLineSettings7;
			displayGridLineSettings8->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings3->ZeroLine = displayGridLineSettings8;
			scopeXAxis2->DataView = displayGridDirectionalLinesSettings3;
			scopeXAxis2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			scopeXAxis2->Format = axisFormat3;
			scopeXAxis2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeXAxis2.InternalData")));
			ticksStart3->StartFrom = 0;
			majorTicks3->StartFrom = ticksStart3;
			majorTicks3->Step = 10;
			scopeXAxis2->MajorTicks = majorTicks3;
			maxScopeAxisValue2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"maxScopeAxisValue2.InternalData")));
			displayOptionalValue13->Enabled = false;
			displayOptionalValue13->Value = 1000;
			displayValueRange7->High = displayOptionalValue13;
			displayOptionalValue14->Enabled = false;
			displayOptionalValue14->Value = -1000;
			displayValueRange7->Low = displayOptionalValue14;
			maxScopeAxisValue2->Range = displayValueRange7;
			basicAxisValue3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicAxisValue3.InternalData")));
			basicAxisValue3->Value = 1024;
			maxScopeAxisValue2->Tick = basicAxisValue3;
			maxScopeAxisValue2->Value = 1024;
			scopeXAxis2->Max = maxScopeAxisValue2;
			scopeMaxSample2->Value = static_cast<System::UInt32>(1024);
			scopeXAxis2->MaxSample = scopeMaxSample2;
			scopeAxisValue2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeAxisValue2.InternalData")));
			displayOptionalValue15->Enabled = false;
			displayOptionalValue15->Value = 1000;
			displayValueRange8->High = displayOptionalValue15;
			displayOptionalValue16->Enabled = false;
			displayOptionalValue16->Value = -1000;
			displayValueRange8->Low = displayOptionalValue16;
			scopeAxisValue2->Range = displayValueRange8;
			basicAxisValue4->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicAxisValue4.InternalData")));
			basicAxisValue4->Value = 0;
			scopeAxisValue2->Tick = basicAxisValue4;
			scopeAxisValue2->Value = 0;
			scopeXAxis2->Min = scopeAxisValue2;
			minorTicks3->Count = static_cast<System::UInt32>(0);
			scopeXAxis2->MinorTicks = minorTicks3;
			axisToolBar3->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons3->ZoomIn = displayToolBarButton33;
			axisToolBarButtons3->ZoomOff = displayToolBarButton34;
			axisToolBarButtons3->ZoomOneDir = displayToolBarButton35;
			axisToolBarButtons3->ZoomOut = displayToolBarButton36;
			axisToolBar3->Buttons = axisToolBarButtons3;
			axisToolBar3->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->ToolBar = axisToolBar3;
			scopeXAxis2->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxisUnitScale2->Exponent = 0;
			scopeXAxis2->UnitScale = scopeXAxisUnitScale2;
			displayViewSize7->Size = static_cast<System::UInt32>(100);
			scopeXAxis2->ViewSize = displayViewSize7;
			displayOptionalValue17->Enabled = false;
			displayOptionalValue17->Value = 100000000;
			displayValueRange9->High = displayOptionalValue17;
			displayOptionalValue18->Enabled = true;
			displayOptionalValue18->Value = 1E-07;
			displayValueRange9->Low = displayOptionalValue18;
			displayAxisZoom3->Range = displayValueRange9;
			scopeXAxis2->Zooming = displayAxisZoom3;
			this->VCScope->XAxis = scopeXAxis2;
			pinList4->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList4.ConnectionData")));
			this->VCScope->XInputPins = pinList4;
			scopeYAxis2->Align = Mitov::PlotLab::ViewAlign::Left;
			scopeAutoScaling2->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace3->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace3->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling2->SpaceAbove = scopeAutoScalingSpace3;
			scopeAutoScalingSpace4->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace4->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling2->SpaceBelow = scopeAutoScalingSpace4;
			scopeYAxis2->AutoScaling = scopeAutoScaling2;
			displayTitleLabel4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(1)));
			displayTitleLabel4->Text = L"V-C (m)";
			scopeYAxis2->AxisLabel = displayTitleLabel4;
			displayViewBackground10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->Background = displayViewBackground10;
			viewButtonSettings4->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->Button = viewButtonSettings4;
			scopeYAxis2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis2->CursorSettings = displayAxisCursorSettings4;
			displayGridLineSettings9->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings4->Lines = displayGridLineSettings9;
			displayGridLineSettings10->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings4->ZeroLine = displayGridLineSettings10;
			scopeYAxis2->DataView = displayGridDirectionalLinesSettings4;
			scopeYAxis2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			scopeYAxis2->Format = axisFormat4;
			scopeYAxis2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeYAxis2.InternalData")));
			ticksStart4->StartFrom = 0;
			majorTicks4->StartFrom = ticksStart4;
			majorTicks4->Step = 10;
			scopeYAxis2->MajorTicks = majorTicks4;
			basicScopeAxisValue3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicScopeAxisValue3.InternalData")));
			displayOptionalValue19->Enabled = false;
			displayOptionalValue19->Value = 1000;
			displayValueRange10->High = displayOptionalValue19;
			displayOptionalValue20->Enabled = false;
			displayOptionalValue20->Value = -1000;
			displayValueRange10->Low = displayOptionalValue20;
			basicScopeAxisValue3->Range = displayValueRange10;
			basicScopeAxisValue3->Value = 1000;
			scopeYAxis2->Max = basicScopeAxisValue3;
			basicScopeAxisValue4->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicScopeAxisValue4.InternalData")));
			displayOptionalValue21->Enabled = false;
			displayOptionalValue21->Value = 1000;
			displayValueRange11->High = displayOptionalValue21;
			displayOptionalValue22->Enabled = false;
			displayOptionalValue22->Value = -1000;
			displayValueRange11->Low = displayOptionalValue22;
			basicScopeAxisValue4->Range = displayValueRange11;
			basicScopeAxisValue4->Value = -1000;
			scopeYAxis2->Min = basicScopeAxisValue4;
			minorTicks4->Count = static_cast<System::UInt32>(0);
			scopeYAxis2->MinorTicks = minorTicks4;
			axisToolBar4->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons4->ZoomIn = displayToolBarButton37;
			axisToolBarButtons4->ZoomOff = displayToolBarButton38;
			axisToolBarButtons4->ZoomOneDir = displayToolBarButton39;
			axisToolBarButtons4->ZoomOut = displayToolBarButton40;
			axisToolBar4->Buttons = axisToolBarButtons4;
			axisToolBar4->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->ToolBar = axisToolBar4;
			scopeYAxis2->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize8->Size = static_cast<System::UInt32>(100);
			scopeYAxis2->ViewSize = displayViewSize8;
			displayOptionalValue23->Enabled = false;
			displayOptionalValue23->Value = 100000000;
			displayValueRange12->High = displayOptionalValue23;
			displayOptionalValue24->Enabled = true;
			displayOptionalValue24->Value = 1E-07;
			displayValueRange12->Low = displayOptionalValue24;
			displayAxisZoom4->Range = displayValueRange12;
			scopeYAxis2->Zooming = displayAxisZoom4;
			this->VCScope->YAxis = scopeYAxis2;
			displayZoom2->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->VCScope->Zooming = displayZoom2;
			// 
			// KCScope
			// 
			this->KCScope->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView1->Background = displayViewBackground1;
			displayGridLineSettings1->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			scopeDataView1->Border = displayGridLineSettings1;
			scopeDataView1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeDataView1.InternalData")));
			this->KCScope->DataView = scopeDataView1;
			this->KCScope->Dock = System::Windows::Forms::DockStyle::Fill;
			channelItemHighlighting1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting1->ChannelLinks = channelItemHighlighting1;
			channelItemHighlighting2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting1->Channels = channelItemHighlighting2;
			displayItemHighlighting1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting1->CursorLinks = displayItemHighlighting1;
			displayItemHighlighting2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting1->Cursors = displayItemHighlighting2;
			displayItemHighlighting3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting1->Ellipses = displayItemHighlighting3;
			displayItemHighlighting4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting1->Markers = displayItemHighlighting4;
			channelMouseHitPoint1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			optionalLabel1->Text = L"";
			channelMouseHitPoint1->PointLabel = optionalLabel1;
			displayHighlighting1->MouseHitPoint = channelMouseHitPoint1;
			displayItemHighlighting5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting1->Zones = displayItemHighlighting5;
			this->KCScope->Highlighting = displayHighlighting1;
			pinList1->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList1.ConnectionData")));
			this->KCScope->InputPins = pinList1;
			this->KCScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"KCScope.InternalData")));
			scopeLegendView1->Align = Mitov::PlotLab::ViewAlign::Right;
			displayViewBackground2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView1->Background = displayViewBackground2;
			legendViewButtonSettings1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView1->Buttons = legendViewButtonSettings1;
			displayLabel1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel1->Text = L"";
			legendGroup1->Caption = displayLabel1;
			scopeLegendView1->ChannelLinks = legendGroup1;
			displayLabel2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel2->Text = L"";
			legendGroup2->Caption = displayLabel2;
			scopeLegendView1->Channels = legendGroup2;
			displayLabel3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel3->Text = L"";
			legendGroup3->Caption = displayLabel3;
			scopeLegendView1->CursorLinks = legendGroup3;
			displayLabel4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel4->Text = L"";
			legendGroup4->Caption = displayLabel4;
			scopeLegendView1->Cursors = legendGroup4;
			displayLabel5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel5->Text = L"";
			legendGroup5->Caption = displayLabel5;
			scopeLegendView1->Ellipses = legendGroup5;
			scopeLegendView1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			scopeLegendView1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeLegendView1.InternalData")));
			displayLabel6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel6->Text = L"";
			legendGroup6->Caption = displayLabel6;
			scopeLegendView1->MarkerGroups = legendGroup6;
			displayViewSize1->Size = static_cast<System::UInt32>(100);
			scopeLegendView1->ViewSize = displayViewSize1;
			displayLabel7->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(0)));
			displayLabel7->Text = L"";
			legendGroup7->Caption = displayLabel7;
			scopeLegendView1->Zones = legendGroup7;
			this->KCScope->Legend = scopeLegendView1;
			this->KCScope->Location = System::Drawing::Point(3, 255);
			this->KCScope->Name = L"KCScope";
			this->KCScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->KCScope->Size = System::Drawing::Size(719, 199);
			this->KCScope->SizeLimit = static_cast<System::UInt32>(0);
			this->KCScope->TabIndex = 2;
			this->KCScope->Text = L"KC Plot";
			displayViewBackground3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle1->Background = displayViewBackground3;
			displayTitle1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 21, Vcl::FontStyles(1)));
			displayTitle1->Text = L"V-C Plot";
			displayViewSize2->Size = static_cast<System::UInt32>(100);
			displayTitle1->ViewSize = displayViewSize2;
			this->KCScope->Title = displayTitle1;
			displayToolBar1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButtons1->Copy = displayToolBarButton1;
			displayToolBarButtons1->Hold = displayToolBarButton2;
			displayToolBarButtons1->Print = displayToolBarButton3;
			displayToolBarButtons1->Save = displayToolBarButton4;
			displayToolBarButtons1->Setup = displayToolBarButton5;
			displayToolBarButtons1->XYZoomOn = displayToolBarButton6;
			displayToolBarButtons1->ZoomIn = displayToolBarButton7;
			displayToolBarButtons1->ZoomMode = displayToolBarButton8;
			displayToolBarButtons1->ZoomNext = displayToolBarButton9;
			displayToolBarButtons1->ZoomOff = displayToolBarButton10;
			displayToolBarButtons1->ZoomOut = displayToolBarButton11;
			displayToolBarButtons1->ZoomPrevious = displayToolBarButton12;
			displayToolBar1->Buttons = displayToolBarButtons1;
			displayToolBar1->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->Position = toolBarPosition1;
			this->KCScope->ToolBar = displayToolBar1;
			displayTrails1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			this->KCScope->Trails = displayTrails1;
			this->KCScope->Visible = true;
			scopeXAxis1->Align = Mitov::PlotLab::ViewAlign::Bottom;
			displayTitleLabel1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(1)));
			displayTitleLabel1->Text = L"UT (hours)";
			scopeXAxis1->AxisLabel = displayTitleLabel1;
			displayViewBackground4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis1->Background = displayViewBackground4;
			viewButtonSettings1->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings1->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings1->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings1->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis1->Button = viewButtonSettings1;
			scopeXAxis1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis1->CursorSettings = displayAxisCursorSettings1;
			displayGridLineSettings2->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings1->Lines = displayGridLineSettings2;
			displayGridLineSettings3->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings1->ZeroLine = displayGridLineSettings3;
			scopeXAxis1->DataView = displayGridDirectionalLinesSettings1;
			scopeXAxis1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			scopeXAxis1->Format = axisFormat1;
			scopeXAxis1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeXAxis1.InternalData")));
			ticksStart1->StartFrom = 0;
			majorTicks1->StartFrom = ticksStart1;
			majorTicks1->Step = 10;
			scopeXAxis1->MajorTicks = majorTicks1;
			maxScopeAxisValue1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"maxScopeAxisValue1.InternalData")));
			displayOptionalValue1->Enabled = false;
			displayOptionalValue1->Value = 1000;
			displayValueRange1->High = displayOptionalValue1;
			displayOptionalValue2->Enabled = false;
			displayOptionalValue2->Value = -1000;
			displayValueRange1->Low = displayOptionalValue2;
			maxScopeAxisValue1->Range = displayValueRange1;
			basicAxisValue1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicAxisValue1.InternalData")));
			basicAxisValue1->Value = 1024;
			maxScopeAxisValue1->Tick = basicAxisValue1;
			maxScopeAxisValue1->Value = 1024;
			scopeXAxis1->Max = maxScopeAxisValue1;
			scopeMaxSample1->Value = static_cast<System::UInt32>(1024);
			scopeXAxis1->MaxSample = scopeMaxSample1;
			scopeAxisValue1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeAxisValue1.InternalData")));
			displayOptionalValue3->Enabled = false;
			displayOptionalValue3->Value = 1000;
			displayValueRange2->High = displayOptionalValue3;
			displayOptionalValue4->Enabled = false;
			displayOptionalValue4->Value = -1000;
			displayValueRange2->Low = displayOptionalValue4;
			scopeAxisValue1->Range = displayValueRange2;
			basicAxisValue2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicAxisValue2.InternalData")));
			basicAxisValue2->Value = 0;
			scopeAxisValue1->Tick = basicAxisValue2;
			scopeAxisValue1->Value = 0;
			scopeXAxis1->Min = scopeAxisValue1;
			minorTicks1->Count = static_cast<System::UInt32>(0);
			scopeXAxis1->MinorTicks = minorTicks1;
			axisToolBar1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons1->ZoomIn = displayToolBarButton13;
			axisToolBarButtons1->ZoomOff = displayToolBarButton14;
			axisToolBarButtons1->ZoomOneDir = displayToolBarButton15;
			axisToolBarButtons1->ZoomOut = displayToolBarButton16;
			axisToolBar1->Buttons = axisToolBarButtons1;
			axisToolBar1->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis1->ToolBar = axisToolBar1;
			scopeXAxis1->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxisUnitScale1->Exponent = 0;
			scopeXAxis1->UnitScale = scopeXAxisUnitScale1;
			displayViewSize3->Size = static_cast<System::UInt32>(100);
			scopeXAxis1->ViewSize = displayViewSize3;
			displayOptionalValue5->Enabled = false;
			displayOptionalValue5->Value = 100000000;
			displayValueRange3->High = displayOptionalValue5;
			displayOptionalValue6->Enabled = true;
			displayOptionalValue6->Value = 1E-07;
			displayValueRange3->Low = displayOptionalValue6;
			displayAxisZoom1->Range = displayValueRange3;
			scopeXAxis1->Zooming = displayAxisZoom1;
			this->KCScope->XAxis = scopeXAxis1;
			pinList2->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList2.ConnectionData")));
			this->KCScope->XInputPins = pinList2;
			scopeYAxis1->Align = Mitov::PlotLab::ViewAlign::Left;
			scopeAutoScaling1->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace1->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace1->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling1->SpaceAbove = scopeAutoScalingSpace1;
			scopeAutoScalingSpace2->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace2->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling1->SpaceBelow = scopeAutoScalingSpace2;
			scopeYAxis1->AutoScaling = scopeAutoScaling1;
			displayTitleLabel2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, Vcl::FontStyles(1)));
			displayTitleLabel2->Text = L"K-C (m)";
			scopeYAxis1->AxisLabel = displayTitleLabel2;
			displayViewBackground5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis1->Background = displayViewBackground5;
			viewButtonSettings2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings2->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings2->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis1->Button = viewButtonSettings2;
			scopeYAxis1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis1->CursorSettings = displayAxisCursorSettings2;
			displayGridLineSettings4->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings2->Lines = displayGridLineSettings4;
			displayGridLineSettings5->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings2->ZeroLine = displayGridLineSettings5;
			scopeYAxis1->DataView = displayGridDirectionalLinesSettings2;
			scopeYAxis1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, Vcl::FontStyles(0)));
			scopeYAxis1->Format = axisFormat2;
			scopeYAxis1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeYAxis1.InternalData")));
			ticksStart2->StartFrom = 0;
			majorTicks2->StartFrom = ticksStart2;
			majorTicks2->Step = 10;
			scopeYAxis1->MajorTicks = majorTicks2;
			basicScopeAxisValue1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicScopeAxisValue1.InternalData")));
			displayOptionalValue7->Enabled = false;
			displayOptionalValue7->Value = 1000;
			displayValueRange4->High = displayOptionalValue7;
			displayOptionalValue8->Enabled = false;
			displayOptionalValue8->Value = -1000;
			displayValueRange4->Low = displayOptionalValue8;
			basicScopeAxisValue1->Range = displayValueRange4;
			basicScopeAxisValue1->Value = 1000;
			scopeYAxis1->Max = basicScopeAxisValue1;
			basicScopeAxisValue2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicScopeAxisValue2.InternalData")));
			displayOptionalValue9->Enabled = false;
			displayOptionalValue9->Value = 1000;
			displayValueRange5->High = displayOptionalValue9;
			displayOptionalValue10->Enabled = false;
			displayOptionalValue10->Value = -1000;
			displayValueRange5->Low = displayOptionalValue10;
			basicScopeAxisValue2->Range = displayValueRange5;
			basicScopeAxisValue2->Value = -1000;
			scopeYAxis1->Min = basicScopeAxisValue2;
			minorTicks2->Count = static_cast<System::UInt32>(0);
			scopeYAxis1->MinorTicks = minorTicks2;
			axisToolBar2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons2->ZoomIn = displayToolBarButton17;
			axisToolBarButtons2->ZoomOff = displayToolBarButton18;
			axisToolBarButtons2->ZoomOneDir = displayToolBarButton19;
			axisToolBarButtons2->ZoomOut = displayToolBarButton20;
			axisToolBar2->Buttons = axisToolBarButtons2;
			axisToolBar2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis1->ToolBar = axisToolBar2;
			scopeYAxis1->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize4->Size = static_cast<System::UInt32>(100);
			scopeYAxis1->ViewSize = displayViewSize4;
			displayOptionalValue11->Enabled = false;
			displayOptionalValue11->Value = 100000000;
			displayValueRange6->High = displayOptionalValue11;
			displayOptionalValue12->Enabled = true;
			displayOptionalValue12->Value = 1E-07;
			displayValueRange6->Low = displayOptionalValue12;
			displayAxisZoom2->Range = displayValueRange6;
			scopeYAxis1->Zooming = displayAxisZoom2;
			this->KCScope->YAxis = scopeYAxis1;
			displayZoom1->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->KCScope->Zooming = displayZoom1;
			// 
			// PhotometryPlotWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(725, 509);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"PhotometryPlotWindow";
			this->Text = L"PhotometryPlotWindow";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VCScope))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->KCScope))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CloseButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void ClearButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

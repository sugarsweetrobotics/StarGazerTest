// -*- C++ -*-
/*!
 * @file  StarGazerTest.cpp
 * @brief Star Gazer Test RTC
 * @date $Date$
 *
 * $Id$
 */

#include "StarGazerTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* stargazertest_spec[] =
  {
    "implementation_id", "StarGazerTest",
    "type_name",         "StarGazerTest",
    "description",       "Star Gazer Test RTC",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Sensor",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "0",
    // Widget
    "conf.__widget__.debug", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
StarGazerTest::StarGazerTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_infoIn("info", m_info)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
StarGazerTest::~StarGazerTest()
{
}



RTC::ReturnCode_t StarGazerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("info", m_infoIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "0");
  // </rtc-template>

  m_infoIn.addConnectorDataListener(ON_BUFFER_WRITE,
				    new MarkerInfoListener());
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t StarGazerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void StarGazerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(stargazertest_spec);
    manager->registerFactory(profile,
                             RTC::Create<StarGazerTest>,
                             RTC::Delete<StarGazerTest>);
  }
  
};



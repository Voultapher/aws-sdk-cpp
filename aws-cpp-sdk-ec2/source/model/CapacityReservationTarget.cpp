﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ec2/model/CapacityReservationTarget.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace EC2
{
namespace Model
{

CapacityReservationTarget::CapacityReservationTarget() : 
    m_capacityReservationIdHasBeenSet(false)
{
}

CapacityReservationTarget::CapacityReservationTarget(const XmlNode& xmlNode) : 
    m_capacityReservationIdHasBeenSet(false)
{
  *this = xmlNode;
}

CapacityReservationTarget& CapacityReservationTarget::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode capacityReservationIdNode = resultNode.FirstChild("CapacityReservationId");
    if(!capacityReservationIdNode.IsNull())
    {
      m_capacityReservationId = StringUtils::Trim(capacityReservationIdNode.GetText().c_str());
      m_capacityReservationIdHasBeenSet = true;
    }
  }

  return *this;
}

void CapacityReservationTarget::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_capacityReservationIdHasBeenSet)
  {
      oStream << location << index << locationValue << ".CapacityReservationId=" << StringUtils::URLEncode(m_capacityReservationId.c_str()) << "&";
  }

}

void CapacityReservationTarget::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_capacityReservationIdHasBeenSet)
  {
      oStream << location << ".CapacityReservationId=" << StringUtils::URLEncode(m_capacityReservationId.c_str()) << "&";
  }
}

} // namespace Model
} // namespace EC2
} // namespace Aws

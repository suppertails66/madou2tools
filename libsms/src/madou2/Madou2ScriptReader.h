#ifndef MADOU2SCRIPTREADER_H
#define MADOU2SCRIPTREADER_H


#include "util/TStream.h"
#include "util/TIfstream.h"
#include "util/TOfstream.h"
#include "util/TBufStream.h"
#include "util/TThingyTable.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>

namespace Sms {


class Madou2ScriptReader {
public:

  struct ResultString {
    std::string str;
    int srcOffset;
    int srcSize;
    int srcSlot;
  };
  
  typedef std::vector<ResultString> ResultCollection;

  Madou2ScriptReader(BlackT::TStream& src__,
//                  BlackT::TStream& dst__,
//                  NesRom& dst__,
                  ResultCollection& dst__,
                  const BlackT::TThingyTable& thingy__);
  
  bool operator()();
protected:

  BlackT::TStream& src;
  ResultCollection& dst;
  BlackT::TThingyTable thingy;
  int lineNum;
  bool breakTriggered;
  
  BlackT::TBufStream currentScriptBuffer;
  int currentScriptSrcOffset;
  int currentScriptSrcSize;
  int currentScriptSrcSlot;
  
  void outputNextSymbol(BlackT::TStream& ifs);
  
//  bool checkSymbol(BlackT::TStream& ifs, std::string& symbol);
  
  void flushActiveScript();
  void resetScriptBuffer();
  
  void processDirective(BlackT::TStream& ifs);
  void processLoadTable(BlackT::TStream& ifs);
  void processStartMsg(BlackT::TStream& ifs);
  void processEndMsg(BlackT::TStream& ifs);
  void processIncBin(BlackT::TStream& ifs);
  void processBreak(BlackT::TStream& ifs);
  void processEndRegion(BlackT::TStream& ifs);
  
  void loadThingy(const BlackT::TThingyTable& thingy__);
  
};


}


#endif

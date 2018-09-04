#include "storage.hpp"
#include "io.hpp"
#include "sorts/index.hpp"

void setup() {
  Storage::setup();
  IO::setup();
  Sorts::setup();
}

void loop() {
  if (IO::inputAvailable()){
    IO::storeInputData();
    if (Sorts::dataSortable()){
      Sorts::sortData();
    }
  }
}

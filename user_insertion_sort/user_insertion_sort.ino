#include "storage.hpp"
#include "io.hpp"
#include "sort.hpp"

void setup() {
  Storage::setup();
  IO::setup();
  Sort::setup();
}

void loop() {
  if (IO::inputAvailable()){
    IO::storeInputData();
    if (Sort::dataSortable()){
      Sort::sortData();
    }
  }
}

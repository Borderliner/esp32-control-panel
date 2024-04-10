#pragma once

#include "system/serial.h"
#include "system/filesystem.h"
#include "config/seeder.h"
#include <sqlite3.h>
/**
 * Must have initialized SPIFFS beforehand
*/
namespace application::db {
static bool is_initialized = false;
sqlite3* database = nullptr;
char* error_message = 0;

bool open_connection(const char *filename, sqlite3 **db) {
   int rc = sqlite3_open(filename, db);
   if (rc) {
       Serial.printf("Can't open database: %s\n", sqlite3_errmsg(*db));
       return false;
   } else {
       Serial.printf("Opened database successfully\n");
   }
   return true;
}

int execute(const char *sql, sqlite3_callback* callback = nullptr) {
   Serial.println(sql);
   long start = micros();
   int rc = sqlite3_exec(database, sql, *callback, nullptr, &error_message);
   if (rc != SQLITE_OK) {
       Serial.printf("SQL error: %s\n", error_message);
       sqlite3_free(error_message);
   } else {
       Serial.printf("SQL executed successfully\n");
   }
   Serial.print(F("Time taken: "));
   Serial.println(micros()-start);
   return rc;
}

void setup_database() {
    if (application::fs::is_initialized) {
        sqlite3_initialize();
        if (open_connection("/spiffs/main.db", &database)) {
            seed_database();
            is_initialized = true;
            
        }
    }
}
}

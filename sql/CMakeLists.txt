add_subdirectory(WintergraspPVPEvent)
add_subdirectory(updates)
add_subdirectory(FULL)

########### install files ###############

FILE(GLOB _SQL *.sql)

install(FILES ${_SQL} DESTINATION share/phantom/sql)

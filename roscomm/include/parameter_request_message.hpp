#ifndef PARAMETER_REQUEST_MESSAGE_HPP
#define PARAMETER_REQUEST_MESSAGE_HPP

enum PARAMETER_REQUEST {
	BOUNDING_BOX,
	MAP_LOCATION,
	ITEM_NAME,
	DISTANCE,
	PLACE_LOCATION,
	WAYPOINT_NAME
};

static const char * PARAMETER_REQUEST_STRINGS[] = { "BOUNDING_BOX,",
                                                    "MAP_LOCATION,",
                                                    "ITEM_NAME,",
                                                    "DISTANCE,",
                                                    "PLACE_LOCATION",
                                                    "WAYPOINT_NAME" };

#endif

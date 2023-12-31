//
// Created by Rayhan on 9/14/2023.
//

#include "TaskNode.h"

TaskNode::TaskNode(string taskName) : taskName(taskName), finished(false), prev(nullptr), next(nullptr) {}

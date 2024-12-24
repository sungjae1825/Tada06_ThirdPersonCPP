#pragma once

#include "CoreMinimal.h"

#define CheckNull(p) { if (p == nullptr) return; }
#define CheckNullResult(p, result) { if (p == nullptr) return result; }

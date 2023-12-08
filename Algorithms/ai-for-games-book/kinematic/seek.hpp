#include <string>

#include "kinematic_data.hpp"

struct ALLEGRO_DISPLAY;
struct ALLEGRO_FONT;

namespace aifg
{
class Seek
{
public:
  Seek();
  Seek(const Seek&) = default;
  Seek& operator=(const Seek&) = default;
  Seek(Seek&&) = default;
  Seek& operator=(Seek&&) = default;

  const inline std::string Name() const { return "Seek"; }

  void Update(ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font);

private:
  void UpdateBodies();

  KinematicBody character;
  KinematicBody target;
};
} // namespace aifg
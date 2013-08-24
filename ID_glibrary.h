#ifndef	__ID_GLIBRARY_H__
#define __ID_GLIBRARY_H__

#include <stdint.h>
#include <pthread.h>
#include <iostream>
#include <list>
#include <vector>

#ifdef	__SDL
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#endif



namespace ID
{
 int Init(int flags);
 int InitWrappers(void);
 int DestroyWrappers();
 void Quit(void);
 void About(void);
};
namespace ID
{
 struct Point
 {
  Point(int16_t _x = 0, int16_t _y = 0) : x(_x), y(_y)
  {
  }

  Point(const Point& p) : x(p.x), y(p.y)
  {
  }

  Point& operator=(const Point& p)
  {
   this->x = p.x;
   this->y = p.y;
   return *this;
  }

  int16_t x;
  int16_t y;
 };

 struct Line
 {
  Line(int16_t x1 = 0, int16_t y1 = 0, int16_t x2 = 0, int16_t y2 = 0) : p1(x1, y1), p2(x2, y2)
  {
  }

  Line(Point _p1, Point _p2) : p1(_p1), p2(_p2)
  {
  }

  Line(const Line& l) : p1(l.p1), p2(l.p2)
  {
  }

  Line& operator=(const Line& l)
  {
   this->p1 = l.p1;
   this->p2 = l.p2;
   return *this;
  }

  Point p1;
  Point p2;
 };

 struct Circle
 {
  Circle(int16_t _x = 0, int16_t _y = 0, double _radius = 0) : center(_x, _y), radius(_radius)
  {
  }

  Circle(Point p, double _radius = 0) : center(p), radius(_radius)
  {
  }

  Circle(const Circle& c) : center(c.center), radius(c.radius)
  {
  }

  Circle& operator=(const Circle& c)
  {
   this->center = c.center;
   this->radius = c.radius;
   return *this;
  }

  Point center;
  double radius;
 };

 struct Rect
 {
  Rect(int16_t _x = 0, int16_t _y = 0,
       uint16_t _w = 0, uint16_t _h = 0) : x(_x), y(_y),
        w(_w), h(_h)
  {
  }

  Rect(const Rect& r) : x(r.x), y(r.y),
          w(r.w), h(r.h)
  {
  }

  Rect& operator=(const Rect& r)
  {
   this->x = r.x;
   this->y = r.y;
   this->w = r.w;
   this->h = r.h;
   return *this;
  }

  int16_t x;
  int16_t y;
  uint16_t w;
  uint16_t h;
 };

 struct Color
 {
  Color(void) : r(0), g(0), b(0), a(0)
  {
  }

  Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) : r(_r), g(_g), b(_b), a(_a)
  {
  }

  Color& operator=(const Color& c)
  {
   this->r = c.r;
   this->g = c.g;
   this->b = c.b;
   this->a = c.a;
   return *this;
  }

  void SetRGBAFromInt(uint32_t c)
  {
   this->r = c >> 24;
   this->g = c >> 16;
   this->b = c >> 8;
   this->a = c;
  }

  uint32_t ConvertToInt()
  {
   uint32_t c;

   c = (this->r << 24) |
       (this->g << 16) |
       (this->b << 8) |
       this->a;
   return c;
  }
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
 };
};



namespace ID
{
 typedef enum
 {




  KEY_UNKNOWN = 0,
  KEY_FIRST = 0,
  KEY_BACKSPACE = 8,
  KEY_TAB = 9,
  KEY_CLEAR = 12,
  KEY_RETURN = 13,
  KEY_PAUSE = 19,
  KEY_ESCAPE = 27,
  KEY_SPACE = 32,
  KEY_EXCLAIM = 33,
  KEY_QUOTEDBL = 34,
  KEY_HASH = 35,
  KEY_DOLLAR = 36,
  KEY_AMPERSAND = 38,
  KEY_QUOTE = 39,
  KEY_LEFTPAREN = 40,
  KEY_RIGHTPAREN = 41,
  KEY_ASTERISK = 42,
  KEY_PLUS = 43,
  KEY_COMMA = 44,
  KEY_MINUS = 45,
  KEY_PERIOD = 46,
  KEY_SLASH = 47,
  KEY_0 = 48,
  KEY_1 = 49,
  KEY_2 = 50,
  KEY_3 = 51,
  KEY_4 = 52,
  KEY_5 = 53,
  KEY_6 = 54,
  KEY_7 = 55,
  KEY_8 = 56,
  KEY_9 = 57,
  KEY_COLON = 58,
  KEY_SEMICOLON = 59,
  KEY_LESS = 60,
  KEY_EQUALS = 61,
  KEY_GREATER = 62,
  KEY_QUESTION = 63,
  KEY_AT = 64,



  KEY_LEFTBRACKET = 91,
  KEY_BACKSLASH = 92,
  KEY_RIGHTBRACKET = 93,
  KEY_CARET = 94,
  KEY_UNDERSCORE = 95,
  KEY_BACKQUOTE = 96,
  KEY_a = 97,
  KEY_b = 98,
  KEY_c = 99,
  KEY_d = 100,
  KEY_e = 101,
  KEY_f = 102,
  KEY_g = 103,
  KEY_h = 104,
  KEY_i = 105,
  KEY_j = 106,
  KEY_k = 107,
  KEY_l = 108,
  KEY_m = 109,
  KEY_n = 110,
  KEY_o = 111,
  KEY_p = 112,
  KEY_q = 113,
  KEY_r = 114,
  KEY_s = 115,
  KEY_t = 116,
  KEY_u = 117,
  KEY_v = 118,
  KEY_w = 119,
  KEY_x = 120,
  KEY_y = 121,
  KEY_z = 122,
  KEY_DELETE = 127,





  KEY_WORLD_0 = 160,
  KEY_WORLD_1 = 161,
  KEY_WORLD_2 = 162,
  KEY_WORLD_3 = 163,
  KEY_WORLD_4 = 164,
  KEY_WORLD_5 = 165,
  KEY_WORLD_6 = 166,
  KEY_WORLD_7 = 167,
  KEY_WORLD_8 = 168,
  KEY_WORLD_9 = 169,
  KEY_WORLD_10 = 170,
  KEY_WORLD_11 = 171,
  KEY_WORLD_12 = 172,
  KEY_WORLD_13 = 173,
  KEY_WORLD_14 = 174,
  KEY_WORLD_15 = 175,
  KEY_WORLD_16 = 176,
  KEY_WORLD_17 = 177,
  KEY_WORLD_18 = 178,
  KEY_WORLD_19 = 179,
  KEY_WORLD_20 = 180,
  KEY_WORLD_21 = 181,
  KEY_WORLD_22 = 182,
  KEY_WORLD_23 = 183,
  KEY_WORLD_24 = 184,
  KEY_WORLD_25 = 185,
  KEY_WORLD_26 = 186,
  KEY_WORLD_27 = 187,
  KEY_WORLD_28 = 188,
  KEY_WORLD_29 = 189,
  KEY_WORLD_30 = 190,
  KEY_WORLD_31 = 191,
  KEY_WORLD_32 = 192,
  KEY_WORLD_33 = 193,
  KEY_WORLD_34 = 194,
  KEY_WORLD_35 = 195,
  KEY_WORLD_36 = 196,
  KEY_WORLD_37 = 197,
  KEY_WORLD_38 = 198,
  KEY_WORLD_39 = 199,
  KEY_WORLD_40 = 200,
  KEY_WORLD_41 = 201,
  KEY_WORLD_42 = 202,
  KEY_WORLD_43 = 203,
  KEY_WORLD_44 = 204,
  KEY_WORLD_45 = 205,
  KEY_WORLD_46 = 206,
  KEY_WORLD_47 = 207,
  KEY_WORLD_48 = 208,
  KEY_WORLD_49 = 209,
  KEY_WORLD_50 = 210,
  KEY_WORLD_51 = 211,
  KEY_WORLD_52 = 212,
  KEY_WORLD_53 = 213,
  KEY_WORLD_54 = 214,
  KEY_WORLD_55 = 215,
  KEY_WORLD_56 = 216,
  KEY_WORLD_57 = 217,
  KEY_WORLD_58 = 218,
  KEY_WORLD_59 = 219,
  KEY_WORLD_60 = 220,
  KEY_WORLD_61 = 221,
  KEY_WORLD_62 = 222,
  KEY_WORLD_63 = 223,
  KEY_WORLD_64 = 224,
  KEY_WORLD_65 = 225,
  KEY_WORLD_66 = 226,
  KEY_WORLD_67 = 227,
  KEY_WORLD_68 = 228,
  KEY_WORLD_69 = 229,
  KEY_WORLD_70 = 230,
  KEY_WORLD_71 = 231,
  KEY_WORLD_72 = 232,
  KEY_WORLD_73 = 233,
  KEY_WORLD_74 = 234,
  KEY_WORLD_75 = 235,
  KEY_WORLD_76 = 236,
  KEY_WORLD_77 = 237,
  KEY_WORLD_78 = 238,
  KEY_WORLD_79 = 239,
  KEY_WORLD_80 = 240,
  KEY_WORLD_81 = 241,
  KEY_WORLD_82 = 242,
  KEY_WORLD_83 = 243,
  KEY_WORLD_84 = 244,
  KEY_WORLD_85 = 245,
  KEY_WORLD_86 = 246,
  KEY_WORLD_87 = 247,
  KEY_WORLD_88 = 248,
  KEY_WORLD_89 = 249,
  KEY_WORLD_90 = 250,
  KEY_WORLD_91 = 251,
  KEY_WORLD_92 = 252,
  KEY_WORLD_93 = 253,
  KEY_WORLD_94 = 254,
  KEY_WORLD_95 = 255,




  KEY_KP0 = 256,
  KEY_KP1 = 257,
  KEY_KP2 = 258,
  KEY_KP3 = 259,
  KEY_KP4 = 260,
  KEY_KP5 = 261,
  KEY_KP6 = 262,
  KEY_KP7 = 263,
  KEY_KP8 = 264,
  KEY_KP9 = 265,
  KEY_KP_PERIOD = 266,
  KEY_KP_DIVIDE = 267,
  KEY_KP_MULTIPLY = 268,
  KEY_KP_MINUS = 269,
  KEY_KP_PLUS = 270,
  KEY_KP_ENTER = 271,
  KEY_KP_EQUALS = 272,




  KEY_UP = 273,
  KEY_DOWN = 274,
  KEY_RIGHT = 275,
  KEY_LEFT = 276,
  KEY_INSERT = 277,
  KEY_HOME = 278,
  KEY_END = 279,
  KEY_PAGEUP = 280,
  KEY_PAGEDOWN = 281,




  KEY_F1 = 282,
  KEY_F2 = 283,
  KEY_F3 = 284,
  KEY_F4 = 285,
  KEY_F5 = 286,
  KEY_F6 = 287,
  KEY_F7 = 288,
  KEY_F8 = 289,
  KEY_F9 = 290,
  KEY_F10 = 291,
  KEY_F11 = 292,
  KEY_F12 = 293,
  KEY_F13 = 294,
  KEY_F14 = 295,
  KEY_F15 = 296,




  KEY_NUMLOCK = 300,
  KEY_CAPSLOCK = 301,
  KEY_SCROLLOCK = 302,
  KEY_RSHIFT = 303,
  KEY_LSHIFT = 304,
  KEY_RCTRL = 305,
  KEY_LCTRL = 306,
  KEY_RALT = 307,
  KEY_LALT = 308,
  KEY_RMETA = 309,
  KEY_LMETA = 310,
  KEY_LSUPER = 311,
  KEY_RSUPER = 312,
  KEY_MODE = 313,
  KEY_COMPOSE = 314,




  KEY_HELP = 315,
  KEY_PRINT = 316,
  KEY_SYSREQ = 317,
  KEY_BREAK = 318,
  KEY_MENU = 319,
  KEY_POWER = 320,
  KEY_EURO = 321,
  KEY_UNDO = 322,

 } Key;

 typedef enum
 {
  KEYMOD_NONE = 0x0000,
  KEYMOD_LSHIFT= 0x0001,
  KEYMOD_RSHIFT= 0x0002,
  KEYMOD_LCTRL = 0x0040,
  KEYMOD_RCTRL = 0x0080,
  KEYMOD_LALT = 0x0100,
  KEYMOD_RALT = 0x0200,
  KEYMOD_LMETA = 0x0400,
  KEYMOD_RMETA = 0x0800,
  KEYMOD_NUM = 0x1000,
  KEYMOD_CAPS = 0x2000,
  KEYMOD_MODE = 0x4000,
  KEYMOD_RESERVED = 0x8000
 } Mod;

 typedef enum
 {
  BUTTON_NONE = 0,
  BUTTON_LEFT,
  BUTTON_MID,
  BUTTON_RIGHT
 } Mouse_Button;






};
namespace ID
{
 typedef enum
 {
  EVENT_CLICK = 1,
  EVENT_DOUBLE_CLICK,
  EVENT_CLICK_DOWN,
  EVENT_CLICK_UP,
  EVENT_ENTER,
  EVENT_LEAVE,
  EVENT_MOTION,
  EVENT_KEY_UP,
  EVENT_KEY_DOWN,
  EVENT_FOCUS_ENTER,
  EVENT_FOCUS_LEAVE,
  EVENT_ENABLE_CHANGE,
  EVENT_SCREEN_CHANGE,
  EVENT_RESIZE,
  EVENT_QUIT,
  EVENT_USER_EVENT
 } EVENT_TYPE;

 typedef struct
 {
  uint8_t scancode;
  Key sym;
  Mod mod;
 } Keysym;

 typedef struct
 {
  uint8_t type;
  Mouse_Button button;
  uint16_t x;
  uint16_t y;
 } t_Click, t_DoubleClick, t_ClickDown, t_ClickUp;

 typedef struct
 {
  uint8_t type;
 } t_Enter, t_Leave;

 typedef struct
 {
  uint8_t type;
  uint8_t state;
  uint16_t x;
  uint16_t y;
  int16_t x_rel;
  int16_t y_rel;
 } t_Motion;

 typedef struct
 {
  uint8_t type;
  Keysym keysym;
 } t_KeyUp, t_KeyDown;

 typedef struct
 {
  uint8_t type;
 } t_FocusEnter, t_FocusLeave;

 typedef struct
 {
  uint8_t type;
  bool isEnable;
 } t_EnableChange;

 typedef struct
 {
  uint8_t type;
  bool isOnScreen;
 } t_ScreenChange;

 typedef struct
 {
  uint8_t type;
  int w;
  int h;
 } t_Resize;

 typedef struct
 {
  uint8_t type;
 } t_Quit;

 typedef union
 {
  uint8_t type;
  t_Click click;
  t_DoubleClick doubleClick;
  t_ClickDown clickDown;
  t_ClickUp clickUp;
  t_Enter enter;
  t_Leave leave;
  t_Motion motion;
  t_KeyUp keyUp;
  t_KeyDown keyDown;
  t_FocusEnter focusEnter;
  t_FocusLeave focusLeave;
  t_EnableChange enableChange;
  t_ScreenChange screenChange;
  t_Resize resize;
  t_Quit quit;
 } Event;
};











namespace ID
{
 class Surface;

 class Wrapper_Interface_Template
 {
 public:
  virtual int Init(void) = 0;
  virtual void Destroy(void) = 0;
  virtual int Update(ID::Surface* s, ID::Rect* rect) = 0;

  virtual int CreateSurface(ID::Surface* surface,
            uint16_t width, uint16_t height,
            uint32_t flags,
            uint32_t rmask, uint32_t gmask,
            uint32_t bmask, uint32_t amask) = 0;
  virtual int SetVideoMode(ID::Surface* surface,
           uint16_t width, uint16_t height,
           uint32_t flags) = 0;
  virtual void DeleteSurface(ID::Surface* surface) = 0;
  virtual uint32_t GetPixel(ID::Surface* surface, uint16_t x, uint16_t y) = 0;
  virtual void SetPixel(ID::Surface* surface,
       uint16_t x, uint16_t y, uint32_t color) = 0;
  virtual int FillRect(ID::Surface* surface, ID::Rect* rect,
       uint32_t color) = 0;
  virtual int BlitSurface(ID::Surface* surface,
          ID::Rect* src_rect,
          ID::Surface* dest,
          int dest_x, int dest_y) = 0;
 private:
  pthread_t __id_thread;
 private:
  pthread_mutex_t __mutex;
 };
};



template <typename T>
class Singleton
{
 public:
  inline static T* GetInstance(void)
  {
   if (_instance == 0)
    _instance = new T;
   return _instance;
  };
  static void Kill(void)
  {
   delete _instance;
   _instance = 0;
  };
 protected:
  Singleton<T>(void)
  {

  }
  virtual ~Singleton<T>(void)
  {
  }
 private:
  static T* _instance;
};

template <typename T>
T* Singleton<T>::_instance = 0;

namespace ID
{
 class Wrapper_Interface : public Wrapper_Interface_Template,
        public Singleton<ID::Wrapper_Interface>
 {
  friend class Singleton<ID::Wrapper_Interface>;
 public:
  typedef SDL_Surface wrapper_surface;

  virtual int Init(void);
  virtual void Destroy(void);
  virtual int Update(Surface* s, Rect* rect);
  virtual int LoadImage(Surface* s, const char* path,
        int x = 0, int y = 0,
        bool resize = true);
  virtual int CreateSurface(Surface* surface,
            uint16_t width, uint16_t height,
            uint32_t flags,
            uint32_t rmask, uint32_t gmask,
            uint32_t bmask, uint32_t amask);
  virtual int SetVideoMode(Surface* surface,
           uint16_t width, uint16_t height,
           uint32_t flags);
  virtual void DeleteSurface(Surface* surface);
  virtual uint32_t GetPixel(Surface* surface, uint16_t x, uint16_t y);
  virtual void SetPixel(Surface* surface,
       uint16_t x, uint16_t y, uint32_t color);
  virtual int FillRect(Surface* surface, Rect* rect,
       uint32_t color);
  virtual int BlitSurface(Surface* surface,
          Rect* src_rect,
          Surface* dest,
          int dest_x, int dest_y);
  void GetRGBA(Surface* surface, uint32_t color,
      Color* struct_color);
  uint32_t MapRGBA(Surface* surface,
      uint8_t red, uint8_t green,
      uint8_t blue, uint8_t alpha);
  inline uint8_t GetColorWithAlpha(uint8_t src_color, uint8_t dst_color,
         uint8_t alpha);
  inline void SetPixelColorWithAlpha(uint8_t* dst, uint8_t* src,
              int sbpp);
  Surface* Morph_SDL_to_ID(SDL_Surface* sdl_surface);
  void CopyPixelsByByte(SDL_Surface* SDL, Surface* ID);
  int SetAlpha(Surface* SDL, uint32_t flags, uint8_t alpha);
  void DBGPrintPixels(Surface* surface);

  void WM_SetCaption(const char* title, const char* icon);
  int WM_IconifyWindow(void);
  int WM_ToggleFullScreen(Surface* surface);
  void WM_SetIcon(Surface* icon, uint8_t* mask);
 private:
  Wrapper_Interface(void);
  ~Wrapper_Interface(void);
 };
};





namespace ID
{
 class Surface
 {
  friend class Wrapper_Interface;
  typedef Wrapper_Interface::wrapper_surface surface;

  public:
     Surface(void);
     Surface(uint16_t width, uint16_t height, uint32_t flags,
      uint32_t rmask, uint32_t gmask,
      uint32_t bmask, uint32_t amask);
     Surface(uint16_t width, uint16_t height, uint32_t flags,
      bool is_set_video_mode);
     Surface(const char* img_to_load);
     ~Surface();
   Surface& operator=(const Surface& surface);
   int Update(Rect* rect);
   Surface* Clone(void);
   int Resize(uint16_t width, uint16_t height, uint32_t flags = SDL_SWSURFACE,
            uint32_t rmask = 0, uint32_t gmask = 0, uint32_t bmask = 0, uint32_t amask = 0);
   int ResizeVideoMode(uint16_t width, uint16_t height);
   int LoadImage(const char* img_to_load,
        int x = 0, int y = 0,
        bool resize = true);
   void SetPixel(uint16_t x, uint16_t y, uint32_t color);
   uint32_t GetPixel(uint16_t x, uint16_t y);
   int FillRect(Rect* rect, Color* color);
   int FillRect(Rect* rect, uint32_t color);
   int BlitSurface(Rect* src_rect,
          Surface* dest,
          int dest_x, int dest_y);
   int TTF_New_Text(const char* font_path, int font_size,
           const char* text, Color fg, int x,
           int y);
   void GetRGBA(uint32_t color, Color* s_color);
   uint32_t MapRGBA(uint8_t red, uint8_t green,
      uint8_t blue, uint8_t alpha);
   int SetAlpha(uint32_t flags, uint8_t alpha);
   uint32_t GetRmask(void);
   uint32_t GetGmask(void);
   uint32_t GetBmask(void);
   uint32_t GetAmask(void);

  public:
   const uint32_t& flags;
   const uint16_t& w;
   const uint16_t& h;
   const uint16_t& pitch;
   void* pixels;

  private:
   uint32_t __flags;
   uint16_t __w;
   uint16_t __h;
   uint16_t __pitch;
   bool __isSetVideoMode;
   surface* __surface;
 };
}

namespace ID
{
 class Font : public Singleton<Font>
 {
  friend class Singleton<Font>;
  public:
   class Police
   {
    public:
     Police(const char* path, int size);
     ~Police();
     TTF_Font* font;
     const char* path;
     int size;
   };
  public:
   Police* LoadFont(const char* path, int size);
   ID::Surface* TextRender(const char* text, Police* font, ID::Color fg);
   int SizeText(TTF_Font* font, const char* text, int* w, int* h);
  protected:
   Police* _SearchFont(const char* font_path, int font_size);
  private:
   Font();
   ~Font();
  private:
   std::vector<Police*> _polices;
 };
}
namespace ID
{
 class Keyboard_Manager : public Singleton<Keyboard_Manager>
 {
  friend class Singleton<Keyboard_Manager>;
  public:
   void Write(std::vector<char>* str, Mod mod, Key sym, unsigned int maxLength);
  private:
   Keyboard_Manager();
   ~Keyboard_Manager();
 };
};













namespace ID
{
 class Drawable;
 class Window;
 class Control;
 typedef void (*callback)(Control* sender, Event* event, void* data);
 class Control
 {
 public:
    Control(void);
    Control(const Control&);
  virtual ~Control(void);
  Control& operator=(const Control&);

  virtual int Click(Event* event);
  virtual int DoubleClick(Event* event);
  virtual int ClickDown(Event* event);
  virtual int ClickUp(Event* event);
  virtual int Enter(Event* event);
  virtual int Leave(Event* event);
  virtual int Motion(Event* event);
  virtual int KeyUp(Event* event);
  virtual int KeyDown(Event* event);
  virtual int FocusEnter(Event* event);
  virtual int FocusLeave(Event* event);
  virtual int EnableChange(Event* event);
  virtual int ScreenChange(Event* event);
  virtual int Resize(Event* event);
  virtual int Quit(Event* event);
  virtual int UserEvent(Event* event);

  void SetCbClick(callback, void* data);
  void SetCbDoubleClick(callback, void* data);
  void SetCbClickDown(callback, void* data);
  void SetCbClickUp(callback, void* data);
  void SetCbEnter(callback, void* data);
  void SetCbLeave(callback, void* data);
  void SetCbMotion(callback, void* data);
  void SetCbKeyUp(callback, void* data, bool global = false);
  void SetCbKeyDown(callback, void* data, bool global = false);
  void SetCbFocusEnter(callback, void* data);
  void SetCbFocusLeave(callback, void* data);
  void SetCbEnableChange(callback, void* data);
  void SetCbScreenChange(callback, void* data);
  void SetCbResize(callback, void* data);
  void SetCbQuit(callback, void* data);
  void SetCbUserEvent(callback, void* data);

  callback GetCbClick(void) const;
  callback GetCbDoubleClick(void) const;
  callback GetCbClickDown(void) const;
  callback GetCbClickUp(void) const;
  callback GetCbEnter(void) const;
  callback GetCbLeave(void) const;
  callback GetCbMotion(void) const;
  callback GetCbKeyUp(void) const;
  callback GetCbKeyDown(void) const;
  callback GetCbFocusEnter(void) const;
  callback GetCbFocusLeave(void) const;
  callback GetCbEnableChange(void) const;
  callback GetCbScreenChange(void) const;
  callback GetCbResize(void) const;
  callback GetCbQuit(void) const;
  callback GetCbUserEvent(void) const;

  virtual void AddChild(Control* control);
  virtual void AddChild(Drawable* drawable);
  virtual int DelChild(Control* control);
  virtual int DelChild(Drawable* drawable);
  int MoveChildTop(Drawable* drawable);
  int MoveChildBot(Drawable* drawable);
  void ClearChilds(void);
  void SetWindow(Window* window);
  void SetParent(Drawable* drawable);
  Window* GetWindow(void) const;
  Drawable* GetParent(void) const;
  std::list<Control*>::iterator GetChildsControl(void);
  std::list<Drawable*>::iterator GetChildsDrawable(void);

  void SetName(const char* name)
  {
   this->__name = name;
  }
  const char* GetName(void) const
  {
   return this->__name;
  }
 protected:
  virtual bool _OnClick(Event* event);
  virtual bool _OnDoubleClick(Event* event);
  virtual bool _OnClickDown(Event* event);
  virtual bool _OnClickUp(Event* event);
  virtual bool _OnEnter(Event* event);
  virtual bool _OnLeave(Event* event);
  virtual bool _OnMotion(Event* event);
  virtual bool _OnKeyUp(Event* event);
  virtual bool _OnKeyDown(Event* event);
  virtual bool _OnFocusEnter(Event* event);
  virtual bool _OnFocusLeave(Event* event);
  virtual bool _OnEnableChange(Event* event);
  virtual bool _OnScreenChange(Event* event);
  virtual bool _OnResize(Event* event);
  virtual bool _OnQuit(Event* event);
  virtual bool _OnUserEvent(Event* event);

 protected:
  Window* _window;
  Drawable* _parent;
  std::list<Control*> _childrenControl;
  std::list<Drawable*> _childrenDrawable;
  callback _cbClick;
  callback _cbDoubleClick;
  callback _cbClickDown;
  callback _cbClickUp;
  callback _cbEnter;
  callback _cbLeave;
  callback _cbMotion;
  callback _cbKeyUp;
  callback _cbKeyDown;
  callback _cbFocusEnter;
  callback _cbFocusLeave;
  callback _cbEnableChange;
  callback _cbScreenChange;
  callback _cbResize;
  callback _cbQuit;
  callback _cbUserEvent;
  void _update();

 protected:
  void* __cbClickData;
  void* __cbDoubleClickData;
  void* __cbClickDownData;
  void* __cbClickUpData;
  void* __cbEnterData;
  void* __cbLeaveData;
  void* __cbMotionData;
  void* __cbKeyUpData;
  void* __cbKeyDownData;
  void* __cbFocusEnterData;
  void* __cbFocusLeaveData;
  void* __cbEnableChangeData;
  void* __cbScreenChangeData;
  void* __cbResizeData;
  void* __cbQuitData;
  void* __cbUserEventData;
  const char* __name;
 };
};

namespace ID
{
 enum REL_POS_TYPE
 {
  REL_POS_NONE = 1,
  REL_POS_TOP = 2,
  REL_POS_BOT = 4,
  REL_POS_LEFT = 8,
  REL_POS_RIGHT = 16,
  REL_POS_CENTER = REL_POS_TOP | REL_POS_BOT | REL_POS_LEFT | REL_POS_RIGHT
 };

 class Drawable : public Control
 {
  public:
    Drawable(void);
    Drawable(uint16_t width, uint16_t height, uint32_t flags,
      uint32_t rmask, uint32_t gmask,
      uint32_t bmask, uint32_t amask);
    Drawable(const Drawable&);
  virtual ~Drawable(void);
  Drawable& operator=(const Drawable&);

  virtual int Click(Event* event);
  virtual int DoubleClick(Event* event);
  virtual int ClickDown(Event* event);
  virtual int ClickUp(Event* event);
  virtual int Enter(Event* event);
  virtual int Leave(Event* event);
  virtual int Motion(Event* event);
  virtual int KeyUp(Event* event);
  virtual int KeyDown(Event* event);
  virtual int FocusEnter(Event* event);
  virtual int FocusLeave(Event* event);
  virtual int EnableChange(Event* event);
  virtual int ScreenChange(Event* event);
  virtual int Resize(Event* event);
  virtual int Quit(Event* event);
  virtual int UserEvent(Event* event);

  void SetOnScreen(bool visible);
  void SetEnable(bool enable);
  void SetInvalidate(bool invalidate);
  void SetSurface(Surface* new_surface);
  void SetPos(int new_x, int new_y);
  void SetPos(REL_POS_TYPE relative_position);
  int SetBackground(Surface* surface);
  int SetBackground(Color* color);
  int SetBackground(uint32_t color);
  void SetVisibleRect(Rect* rect);

  bool GetOnScreen(void) const;
  bool GetEnable(void) const;
  bool GetInvalidate(void) const;
  Surface* GetSurface(void) const;
  void GetPos(int* x, int* y) const;
  REL_POS_TYPE GetRelPos(void) const;
  void GetOffset(int* offset_x, int* offset_y) const;
  uint16_t GetWidth(void) const;
  uint16_t GetHeight(void) const;
  Rect* GetVisibleRect(void) const;
  Window* GetRealWindow(void);

  int BlitSurface(Rect* rect, Surface* surface, int x, int y);
  virtual int RefreshToSurface(Surface* surface, int x, int y);
  virtual int Resize(uint16_t width, uint16_t height,
           uint32_t flags = SDL_SWSURFACE | SDL_SRCALPHA,
           uint32_t rmask = 0, uint32_t gmask = 0,
           uint32_t bmask = 0, uint32_t amask = 0);

 protected:
  void _RefreshBackground(void);
  int _BlitToParent(void);
  virtual void _SetInvalidate(bool invalidate);
  void _AddUpdateRect(void);
  void _RefreshOffset(void);
  void _CalculRelativePosition(int* x, int* y);
  virtual bool _OnClick(Event* event);
  virtual bool _OnDoubleClick(Event* event);
  virtual bool _OnClickDown(Event* event);
  virtual bool _OnClickUp(Event* event);
  virtual bool _OnEnter(Event* event);
  virtual bool _OnLeave(Event* event);
  virtual bool _OnMotion(Event* event);
  virtual bool _OnKeyUp(Event* event);
  virtual bool _OnKeyDown(Event* event);
  virtual bool _OnFocusEnter(Event* event);
  virtual bool _OnFocusLeave(Event* event);
  virtual bool _OnEnableChange(Event* event);
  virtual bool _OnScreenChange(Event* event);
  virtual bool _OnResize(Event* event);
  virtual bool _OnQuit(Event* event);
  virtual bool _OnUserEvent(Event* event);

 protected:
  Surface* _surface;
  Surface* _bgSurface;
  Color _bgColor;
  bool _onScreen;
  bool _isEnable;
  bool _isInvalidate;
  REL_POS_TYPE _relPos;
  int _x;
  int _y;
  Rect* _visibleRect;
  int _offset_x;
  int _offset_y;





 };
}

namespace ID
{
 class Container : public Drawable
 {
  public:
   Container(void);
   Container(uint16_t w, uint16_t h, uint32_t flags,
      uint32_t rmask, uint32_t gmask,
      uint32_t bmask, uint32_t amask);
  virtual ~Container(void);
 };
};










namespace ID
{
 class Button : public Drawable
 {
 public:
    Button(void);
    Button(uint16_t w, uint16_t h, uint16_t f,
           uint32_t rmask, uint32_t gmask,
           uint32_t bmask, uint32_t amask);
    Button(const ID::Button& button);
  virtual ~Button(void);
  virtual int RefreshToSurface(Surface* surface, int x, int y);
 };
}







namespace ID
{
 const Color COLOR_BLACK = ID::Color(0, 0, 0, 255);
 const Color COLOR_WHITE = ID::Color(255, 255, 255, 255);
};

namespace ID
{
 class Label : public Drawable
 {
  public:
     Label(const char* font_path, int font_size, const char* text,
           Color fg = COLOR_BLACK);
     Label(const ID::Label& b);
   virtual ~Label();
   const char* GetText(void) const;
   void SetText(const char* Text);
   void SetColor(Color fg);
   void SetColor(uint32_t fg);
   Color GetColor(void) const;
   void SetPolice(Font::Police* police);
   Font::Police* GetPolice(void) const;
   virtual int RefreshToSurface(Surface* surface, int x, int y);

  private:
   const char* __text;
   Color __color;
   Font::Police* __police;
 };
}

namespace ID
{
 class Button_Label : public Button
 {
  public:
    Button_Label(uint16_t width, uint16_t height, uint32_t flags,
          uint32_t rmask, uint32_t gmask,
          uint32_t bmask, uint32_t amask);
    Button_Label(uint16_t width, uint16_t height, uint32_t flags,
          uint32_t rmask, uint32_t gmask,
          uint32_t bmask, uint32_t amask,
          const char* font_path, int font_size, const char* label,
          Color fg = COLOR_BLACK);
    Button_Label(const Button_Label& button);
  virtual ~Button_Label(void);
  void SetLabel(Label* label);
  Label* GetLabel(void) const;
  void SetLabelPos(int x, int y);
  void SetLabelPos(REL_POS_TYPE rel_pos);
  void GetLabelPos(int* x, int* y)const;
  REL_POS_TYPE GetLabelRelPos(void)const;
  virtual int RefreshToSurface(Surface* surface, int x, int y);

  private:
   ID::Label* __label;
 };
}

namespace ID
{
 enum MENU_TYPE
 {
  MENU_VERTICAL = 1,
  MENU_HORIZONTAL = 2
 };

 enum ALIGNMENT_TYPE
 {
  ALIGNMENT_TOP = 1,
  ALIGNMENT_LEFT = 1,
  ALIGNMENT_BOT = 2,
  ALIGNMENT_RIGHT = 2,
  ALIGNMENT_CENTER = 3
 };

 enum SIDE_POSITION_TYPE
 {
  SIDE_POSITION_TOP = 1,
  SIDE_POSITION_BOT,
  SIDE_POSITION_LEFT,
  SIDE_POSITION_RIGHT
 };

 class Menu : public Drawable
 {
  friend class Menubar;
  public:
     Menu(uint16_t w, uint16_t h, uint32_t flags,
          uint32_t rmask, uint32_t gmask,
          uint32_t bmask, uint32_t amask,
          const char* font_path, int font_size,
          const char* text, Color color = COLOR_BLACK);
   virtual ~Menu(void);

   void SetMenuType(MENU_TYPE menu_type);
   void SetChildrenSidePosition(SIDE_POSITION_TYPE side_position_type);
   void SetChildrenAlignment(ALIGNMENT_TYPE alignment_type);
   void SetMustBeOnScreen(bool mustBeOnScreen);
   void SetButtonLabel(Button_Label* button_label);

   MENU_TYPE GetMenuType(void) const;
   std::list<Menu*> GetChildrenMenu(void) const;
   SIDE_POSITION_TYPE GetChildrenSidePosition(void) const;
   ALIGNMENT_TYPE GetChildrenAlignment(void) const;
   bool GetMustBeOnScreen(void) const;
   Button_Label* GetButtonLabel(void) const;

   void ShowAll();
   void HideAll();

   virtual int Click(Event* event);
   virtual int DoubleClick(Event* event);
   virtual int ClickDown(Event* event);
   virtual int ClickUp(Event* event);
   virtual int Enter(Event* event);
   virtual int Leave(Event* event);
   virtual int Motion(Event* event);
   virtual int KeyUp(Event* event);
   virtual int KeyDown(Event* event);
   virtual int FocusEnter(Event* event);
   virtual int FocusLeave(Event* event);
   virtual int EnableChange(Event* event);
   virtual int ScreenChange(Event* event);
   virtual int Resize(Event* event);
   virtual int Quit(Event* event);
   virtual int UserEvent(Event* event);

   int ActionEvent(void);
   void SetCbActionEvent(callback, void* data);
   callback GetCbActionEvent(void);

   virtual void AddChild(Menu* menu);
   virtual int DelChild(Menu* menu);
   virtual int RefreshToSurface(Surface* surface, int x, int y);

  protected:
   void _SetToReorganize(bool toReorganize);
   bool _GetToReorganize(void);

   void _Reorganize(void);
   int _BlitToWindow(void);

   virtual bool _OnClick(Event* event);
   virtual bool _OnDoubleClick(Event* event);
   virtual bool _OnClickDown(Event* event);
   virtual bool _OnClickUp(Event* event);
   virtual bool _OnEnter(Event* event);
   virtual bool _OnLeave(Event* event);
   virtual bool _OnMotion(Event* event);
   callback _cbActionEvent;

  protected:
   Button_Label* _buttonLabel;

  private:
   void __ReorganizeVertical(void);
   void __ReorganizeHorizontal(void);
   int __GetChildrenMaxWidth(void);
   int __GetChildrenTotalWidth(void);
   int __GetChildrenMaxHeight(void);
   int __GetChildrenTotalHeight(void);
   void __CalculChildrenSidePosition(int* x, int* y);
   void __CalculChildrenAlignment(int* x, int* y,
          int minX, int minY);

  private:
   MENU_TYPE __menuType;
   std::list<Menu*> __childrenMenu;
   SIDE_POSITION_TYPE __childrenSidePosition;
   ALIGNMENT_TYPE __childrenAlignment;
   bool __mustBeOnScreen;
   bool __toReorganize;
   void* __cbActionEventData;
 };
};




namespace ID
{
 class Menubar : public Drawable
 {
  public:
     Menubar(uint16_t w, uint16_t h, uint32_t flags,
      uint32_t rmask, uint32_t gmask,
      uint32_t bmask, uint32_t amask,
      REL_POS_TYPE relPos = REL_POS_TOP);
   virtual ~Menubar(void);

   virtual void AddChild(Menu* menu);
   virtual int RefreshToSurface(Surface* surface, int x, int y);

   virtual int Click(Event* event);
   virtual int DoubleClick(Event* event);
   virtual int ClickDown(Event* event);
   virtual int ClickUp(Event* event);
   virtual int Enter(Event* event);
   virtual int Leave(Event* event);
   virtual int Motion(Event* event);
   virtual int KeyUp(Event* event);
   virtual int KeyDown(Event* event);
   virtual int FocusEnter(Event* event);
   virtual int FocusLeave(Event* event);
   virtual int EnableChange(Event* event);
   virtual int ScreenChange(Event* event);
   virtual int Resize(Event* event);
   virtual int Quit(Event* event);
   virtual int UserEvent(Event* event);

  protected:
   void _Reorganize(void);
   virtual void _SetInvalidate(bool invalidate);
   virtual bool _OnClick(ID::Event* event);
   virtual bool _OnDoubleClick(ID::Event* event);
   virtual bool _OnClickDown(ID::Event* event);
   virtual bool _OnClickUp(ID::Event* event);
   virtual bool _OnEnter(ID::Event* event);
   virtual bool _OnLeave(ID::Event* event);
   virtual bool _OnMotion(ID::Event* event);

  private:
   std::list<Menu*> __childrenMenu;
 };
};




namespace ID
{
 class Main_Control : public Drawable
 {
  public:
     Main_Control(uint16_t width, uint16_t height, uint32_t flags,
           uint32_t rmask, uint32_t gmask,
           uint32_t bmask, uint32_t amask);
     Main_Control(const Main_Control& mc);
   virtual ~Main_Control();
   Main_Control& operator=(const Main_Control& mc);

   bool GetInvalidate(void) const;
   virtual int RefreshToSurface(Surface* surface, int x, int y);

  protected:
   virtual void _SetInvalidate(bool invalidate);
 };
};








void __id_textboxClickDown(ID::Control* _tb, ID::Event*, void*);
void __id_textboxKeyDown(ID::Control* _tb, ID::Event* e, void*);

namespace ID
{
 class Textbox : public Drawable
 {
  friend void ::__id_textboxKeyDown(ID::Control*, ID::Event*, void*);
  public:
     Textbox(void);
     Textbox(uint16_t w, uint16_t h, uint32_t f,
      uint32_t rmask, uint32_t gmask,
      uint32_t bmask, uint32_t amask,
      const char* font_path, int font_size,
      Color fg = COLOR_BLACK);
     Textbox(const ID::Textbox& button);
   virtual ~Textbox(void);
   void SetText(char* text);
   char* GetText(void);
   void SetColor(Color fg);
   void SetColor(uint32_t fg);
   Color GetColor(void) const;
   void SetPolice(Font::Police* police);
   Font::Police* GetPolice(void) const;
   void SetMaxLength(unsigned int maxLength);
   unsigned int GetMaxLength(void) const;
   virtual int RefreshToSurface(Surface* surface, int x, int y);

  private:
   int __maxLength;
   std::vector<char> __text;
   Color __color;
   Font::Police* __police;
 };
}








void __id_textareaClickDown(ID::Control* textbox, ID::Event* event, void* data);
void __id_textareaKeyDown(ID::Control* textbox, ID::Event* event, void* data);

namespace ID
{
 class Textarea : public Drawable
 {
  friend void ::__id_textareaKeyDown(ID::Control*, ID::Event*, void*);
  public:
     Textarea(void);
     Textarea(uint16_t w, uint16_t h, uint32_t f,
      uint32_t rmask, uint32_t gmask,
      uint32_t bmask, uint32_t amask,
      const char* font_path, int font_size,
      Color fg = COLOR_BLACK);
     Textarea(const ID::Textarea& button);
   virtual ~Textarea(void);
   void SetText(char* text);
   char* GetText(void);
   void SetColor(Color fg);
   void SetColor(uint32_t fg);
   Color GetColor(void) const;
   void SetPolice(Font::Police* police);
   Font::Police* GetPolice(void) const;
   void SetMaxLength(unsigned int maxLength);
   unsigned int GetMaxLength(void) const;
   virtual int RefreshToSurface(Surface* surface, int x, int y);

  private:
   unsigned int __maxLength;
   std::vector<char> __text;
   Color __color;
   Font::Police* __police;
 };
}




namespace ID
{
 class Button_Image : public Button
 {
 public:
    Button_Image(uint16_t w, uint16_t h, uint16_t f,
          uint32_t rmask, uint32_t gmask,
          uint32_t bmask, uint32_t amask);
    Button_Image(const char* image_path);
    Button_Image(const Button_Image& button_image);
  virtual ~Button_Image(void);
  void SetImage(Surface* surface);
  Surface* GetImage(void) const;
  void SetImagePosition(int x, int y);
  void SetImageVisible(Rect* rect);
  void GetImageVisible(Rect* rect) const;
  virtual int RefreshToSurface(Surface* surface, int x, int y);
 private:
  Surface* __image;
  int __imgX;
  int __imgY;
  Rect* __imgRect;
 };
}







namespace ID
{
 class Window : public Control
 {
  public:
     Window(uint16_t width, uint16_t height, uint32_t flags);
     Window(const Window& window);
   virtual ~Window(void);
   Window& operator=(const Window& window);

   virtual int Click(Event* event);
   virtual int DoubleClick(Event* event);
   virtual int ClickDown(Event* event);
   virtual int ClickUp(Event* event);
   virtual int Enter(Event* event);
   virtual int Leave(Event* event);
   virtual int Motion(Event* event);
   virtual int KeyUp(Event* event);
   virtual int KeyDown(Event* event);
   virtual int FocusEnter(Event* event);
   virtual int FocusLeave(Event* event);
   virtual int EnableChange(Event* event);
   virtual int ScreenChange(Event* event);
   virtual int Resize(Event* event);
   virtual int Quit(Event* event);
   virtual int UserEvent(Event* event);

   void SetInvalidate(bool invalidate);
   int SetBackground(Surface* surface);
   int SetBackground(Color* color);
   int SetBackground(uint32_t color);
   void SetDrawableFocused(Drawable* focused);

   Drawable* GetMainControl(void) const;
   bool GetInvalidate(void) const;
   uint16_t GetWidth(void) const;
   uint16_t GetHeight(void) const;
   Drawable* GetDrawableFocused(void) const;
   Surface* GetSurface(void);
   std::vector<Menu*>* GetDeveloppedMenus(void);

   int RefreshSurface(void);
   void AddUpdate(Rect* rect);
   int Update(void);
   int Update(Rect* rect);
   int Resize(uint16_t width, uint16_t height);

   void AddMenubar(Menubar* menubar);
   int DelMenubar(Menubar* menubar);
   virtual void AddChild(Control* control);
   virtual void AddChild(Drawable* drawable);

  protected:
   int _Reorganize(void);
   void _SetToReorganize(bool toReorganize);
   bool _GetToReorganize(void) const;
   void _RefreshBackground(void);

   virtual bool _OnClick(Event* event);
   virtual bool _OnDoubleClick(Event* event);
   virtual bool _OnClickDown(Event* event);
   virtual bool _OnClickUp(Event* event);
   virtual bool _OnEnter(Event* event);
   virtual bool _OnLeave(Event* event);
   virtual bool _OnMotion(Event* event);
   virtual bool _OnKeyUp(Event* event);
   virtual bool _OnKeyDown(Event* event);
   virtual bool _OnFocusEnter(Event* event);
   virtual bool _OnFocusLeave(Event* event);
   virtual bool _OnEnableChange(Event* event);
   virtual bool _OnScreenChange(Event* event);
   virtual bool _OnResize(Event* event);
   virtual bool _OnQuit(Event* event);
   virtual bool _OnUserEvent(Event* event);

  private:
   Surface __window;
   Main_Control* __mainControl;
   bool __isInvalidate;
   Surface* __bgSurface;
   Color __bgColor;
   Drawable* __drawableFocused;
   std::vector<Rect> __updateRects;
   bool __fullscreenUpdate;
   bool __toReorganize;
   std::vector<Menu*> __developpedMenus;
 };
}














namespace ID
{
 class Wrapper_Event_Template
 {
 public:
  static void* WrapEvent(void*);
  virtual int Init(void) = 0;
  virtual void Destroy(void) = 0;
  virtual int WaitEvent(ID::Event* event) = 0;
  virtual int PollEvent(ID::Event* event) = 0;
 private:
  pthread_t __id_thread;
 private:
  pthread_mutex_t __mutex;
 };
};



namespace ID
{
 class Wrapper_Event : public Wrapper_Event_Template,
    public Singleton<ID::Wrapper_Event>
 {
   friend class Singleton<ID::Wrapper_Event>;

  public:
   static void* WrapEvent(void*);
   int Init(void);
   void Destroy(void);
   int WaitEvent(Event* event);
   int PollEvent(Event* event);
   void AddKeyUpControl(Control* control);
   void AddKeyDownControl(Control* control);
   void DelKeyUpControl(Control* control);
   void DelKeyDownControl(Control* control);
   void ApplyKeyUp(ID::Event* e);
   void ApplyKeyDown(ID::Event* e);

  private:
   Wrapper_Event(void);
   ~Wrapper_Event(void);

  private:
   pthread_t __id_thread;
   bool __alive;
   pthread_mutex_t __mutex;

   Event* __events_queue;
   int __events_size;
   std::list<Control*> __keyDownControl;
   std::list<Control*> __keyUpControl;
 };
};


#endif

#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <QImage>
#include <string>

enum GameId {
  one = 1,
  two = 2,
  three = 3,
};

struct Image {
  std::string filename;
  std::string name;
  GameId gameId;
  bool chosen;
};

const Image images[] = {
    // Labs Name
    {
        "MDC-Boston-vector.jpg",
        "BOSTON",
        one,
        false,
    },
    {"MDC-Chicago-vector.jpg", "CHICAGO", one, false},
    {
        "california.jpg",
        "CALIFORNIA",
        one,
        true,

    },
    {
        "sunDance.jpg",
        "SUNDANCE",
        one,
        false,
    },
    {
        "MDC-Phoenix-vector.jpg",
        "PHOENIX",
        one,
        true,
    },
    {
        "MDC-Wilmington-vector.jpg",
        "WILMINGTON",
        one,
        false,
    },
    {
        "quantum_rgb.jpg",
        "QUANTUM",
        one,
        false,
    },
    {
        "ADL.jpg",
        "ADL",
        one,
        true,
    },

    {
        "MDC-Phoenix-vector.jpg",
        "PHOENIX",
        one,
        true,
    },
    {
        "image4.jpg",
        "WARD",
        one,
        false,
    },
    {
        "mitch.jpg",
        "MITCH",
        one,
        true,
    },
    {
        "becden.jpg",
        "BECDEN",
        one,
        false,
    },

    // Product Name
    {
        "MDN_GoldCrownFullCast.jpg",
        "FULL METAL",
        two,
        false,
    },
    {
        "RespireBlue+.jpg",
        "SLEEP",
        two,
        false,
    },
    {
        "Implant.jpg",
        "IMPLANT",
        two,
        true,
    },
    {
        "IPS+emax.jpg",
        "E.MAX",
        two,
        true,
    },
    {
        "PtwoZ.jpg",
        "PtwoZ",
        two,
        false,
    },
    {
        "MDN+Metal+Frame.jpg",
        "SPACE MANINTAINERS",
        two,
        false,
    },
    {
        "PFM.jpg",
        "PFM",
        two,
        false,
    },
    {
        "CHROME-Guided-Smile_Osteotomy.jpg",
        "CHORME GUIDEDSMILE",
        two,
        true,
    },
    {
        "Composite.jpg",
        "COMPOSITE",
        two,
        false,
    },
    {
        "ZEUS+Crown.jpg",
        "ZEUS",
        two,
        false,
    },
    {
        "MDN+Acrylic+Bite+Guard.jpg",
        "DIGITAL SPLINTS",
        two,
        true,
    },
    {
        "Prime.jpg",
        "Prime",
        two,
        false,
    },
    {
        "HyBrid+Denture.jpg",
        "HYBRID DENTURE",
        two,
        true,
    },
    {
        "Valplast.jpg",
        "VALPLAST",
        two,
        false,
    },
    {
        "Composite.jpg",
        "COMPOSITE",
        two,
        false,
    },
    // CELEBRITLY SMILES
    {
        "JACHIE CHAN.jpg",
        "JACHIE CHAN",
        three,
        false,
    },
    {
        "LADY GAGA.jpg",
        "LADY GAGA",
        three,
        false,
    },
    {
        "BEYONCE.jpg",
        "BEYONCE",
        three,
        true,
    },
    {
        "LEONARDO.jpg",
        "LEONARDO DICAPRIO",
        three,
        false,
    },
    {
        "emma-watson-cute-smile-new-1440x2960.jpg",
        "EMMA WATSON",
        three,
        false,
    },
    {
        "MICHAEL JACKSON.jpg",
        "MICHAEL JACKSON",
        three,
        false,
    },
    {
        "061417-jennifer-lopez-lead.jpg",
        "JENNIFER LOPEZ",
        three,
        true,
    },
    {
        "adam.jpg",
        "ADAM LEVINE",
        three,
        false,
    },
    {
        "SELENA GOMEZ.jpg",
        "SELENA GOMEZ",
        three,
        false,
    },
    {
        "rianna-rihanna-ulybka-zuby.jpg",
        "RIHANNA",
        three,
        false,
    },
    {
        "bruno mars.jpg",
        "BRUNO MARS",
        three,
        true,
    },
    {
        "steve-harvey.jpg",
        "STEVE HARVEY",
        three,
        true,
    },
    {
        "ronaldo-wallpaper-2101three022250471280x1280.jpg",
        "CRISTIANO RONALDO",
        three,
        false,
    },
    {
        "angelina-jolie-smile-wallpaper-50threethree0-52020-hd-wallpapers.jpg",
        "ANGELINA JOLIE",
        three,
        false,
    },
    {
        "THE ROCK.jpg",
        "THE ROCK",
        three,
        true,
    },
    {
        "wallpapersden.com_samuel-l-jackson-armband-smile_2048x27three2.jpg",
        "SAMUEL JACKSON",
        three,
        false,
    },
    {
        "gTy_Justin_Tmberlake_hb_160805_16x9_1600.jpg",
        "JUSTIN TIMBERLAKE",
        three,
        false,
    },
    {
        "skysports-naomi-osaka-tennis_4548three4three.jpg",
        "NAOMI OSAKA",
        three,
        false,
    }};

#endif // GAME_INFO_H

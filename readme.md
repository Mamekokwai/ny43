# ny43

A 43-key custom mechanical keyboard.

## Layout

```
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│K00│K01│K02│K03│K04│K05│K06│K07│K08│K09│K10│K11│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
│K100 │K101│K102│K103│K104│K105│K106│K107│K108│K109│K110  │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┤
│K200  │K201│K202│K203│K204│K205│K206│K207│K208│K209│K210│
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬──┴────┤
│K300    │K301│K302│K303│     │K305│K306│K307│K308│K309   │
└────────┴───┴───┴───┴───────┴───┴───┴───┴───┴────────┘
```

## Features

- 43 keys
- ATMega32U4 microcontroller
- RGB Matrix support
- VIA support

## Build

Make example for this keyboard (after setting up your build environment):

```bash
qmk compile -kb ny43 -km via
```

## Flashing

```bash
qmk flash -kb ny43 -km via
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

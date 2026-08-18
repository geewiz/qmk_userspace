# QMK userspace

## Builds

Use in-place Git branches: QMK builds require this repository root as the userspace overlay. From `../qmk_firmware`, run Docker builds with `QMK_USERSPACE="$(realpath ../qmk_userspace)" ./util/docker_build.sh <keyboard>:geewiz`; use `planck/rev6:geewiz` for the Planck.

## Layout changes

Treat keyboard-layout changes as declarative configuration. Validate them with the appropriate QMK Docker build rather than TDD.

## Keyboard specifics

### Planck

The Planck mirrors the split keyboards' positional semantics while retaining its encoder. It omits a Media layer; its Adjust-layer RGB positions remain intentional no-ops because lighting is disabled.
